description('Ensures that assertion failures don\'t occur on updating the value of &lt;output&gt; elements.');

debug('- A test in the value is set twice.');
var output = document.createElement('output');
document.body.appendChild(output);
output.value = '';
output.value = '';
testPassed('Not crashed');
document.body.removeChild(output);

debug('');
debug('- A test in the value is set to different values twice.');
output = document.createElement('output');
document.body.appendChild(output);
output.value = '';
output.value = 'foo';
testPassed('Not crashed');
document.body.removeChild(output);

debug('');
debug('- A test in reset events occur twice when there is no default value.');
var form = document.createElement('form');
document.body.appendChild(form);
output = document.createElement('output');
form.appendChild(output);
form.reset();
form.reset();
testPassed('Not crashed');
document.body.removeChild(form);

debug('');
debug('- A test in reset events occur twice when the value is the same as the default value.');
form = document.createElement('form');
document.body.appendChild(form);
output = document.createElement('output');
output.defaultValue = 'foo';
output.value = 'foo';
form.appendChild(output);
form.reset();
form.reset();
testPassed('Not crashed');
document.body.removeChild(form);
