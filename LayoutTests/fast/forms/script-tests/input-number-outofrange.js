description('Test for spinbutton behavior for out-of-range values.');

var parent = document.createElement('div');
document.body.appendChild(parent);
parent.innerHTML = '<input type=number id=lower value=-10 min=0 max=100>'
    + '<input type=number id=higher value=200 min=0 max=100>';
var lower = document.getElementById('lower');
var higher = document.getElementById('higher');

function sendKeyEvent(element, key)
{
    element.focus();
    var event = document.createEvent('KeyboardEvents');
    event.initKeyboardEvent('keydown', true, true, document.defaultView, key, 0, false, false, false, false, false);
    element.dispatchEvent(event);
}

debug('Pressing the down arrow key on an input field of which value is lower than the minimum:');
sendKeyEvent(lower, 'Down');
var unchanged = "-10";
shouldBe('lower.value', 'unchanged');

debug('Pressing the up arrow key on the input:');
sendKeyEvent(lower, 'Up');
shouldBe('lower.value', 'lower.min');

debug('Pressing the up arrow key on an input field of which value is higher than the maximum:');
sendKeyEvent(higher, 'Up');
unchanged = "200";
shouldBe('higher.value', 'unchanged');

debug('Pressing the down arrow key on the input:');
sendKeyEvent(higher, 'Down');
shouldBe('higher.value', 'higher.max');

parent.innerHTML = '';
