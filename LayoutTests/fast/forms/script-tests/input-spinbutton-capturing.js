description('Test for a capturing bug of spin buttons in a type=numnber input.');

var parent = document.createElement('div');
document.body.appendChild(parent);
parent.innerHTML = '<input type=number id=number value=0 min=0 max=100><input type=number id=another value=1 min=0 max=100>';
var numberInput = document.getElementById('number');
var anotherInput = document.getElementById('another');

if (window.eventSender) {
    // Move the cursor on the upper button of the first input field.
    eventSender.mouseMoveTo(numberInput.offsetLeft + numberInput.offsetWidth - 10, numberInput.offsetTop + numberInput.offsetHeight / 4);

    // Move the cursor on the upper button of another input field, and click.
    // There was a bug that a capturing flag of the first input field was not
    // clear and this click didn't work.
    eventSender.mouseMoveTo(anotherInput.offsetLeft + anotherInput.offsetWidth - 10, anotherInput.offsetTop + anotherInput.offsetHeight / 4);
    eventSender.mouseMoveTo(anotherInput.offsetLeft + anotherInput.offsetWidth - 10, anotherInput.offsetTop + anotherInput.offsetHeight / 4 - 1);
    eventSender.mouseDown();
    eventSender.mouseUp();
    shouldBe('anotherInput.value', '"2"');

    parent.innerHTML = '';
} else {
    document.getElementById('console').innerHTML = '<p>No eventSender. <p>Manual test instruction: Click the upper button of the first input field, then click the upper button of the second input field.  Confirm that the second input field value is changed.';
}
