description('This test aims to check for typeMismatch flag with type=number input fields');

var i = document.createElement('input');
i.type = 'number';

function check(value, disabled)
{
    i.value = value;
    i.disabled = !!disabled;
    var mismatch = i.validity.typeMismatch;
    var resultText = '"' + value + '" is ' + (mismatch ? 'an invalid' : 'a valid') + ' number' + (disabled ? ' when disabled.' : '.');
    if (!mismatch)
        testPassed(resultText);
    else
        testFailed(resultText);
}

function checkSanitization(value, expectedValue)
{
    i.value = value;
    if (i.validity.typeMismatch) {
        testFailed('"' + value + '" made typeMismatch true.');
    } else if (i.value != expectedValue) {
        testFailed('"' + value + '" was sanitized to "' + i.value + '". It should be ' + expectedValue);
    } else {
        testPassed('"' + value + '" was sanitized to "' + i.value + '".');
    }
}

// Valid values
check('0');
check('10');
check('01');
check('0.2');
check('.2');
check('-0');
check('-1.2');
check('1.2E10');
check('1.2E-10');
check('1.2E+10');
check('12345678901234567890123456789012345678901234567890');
check('0.12345678901234567890123456789012345678901234567890');

// Invalid values
checkSanitization('abc', '');
checkSanitization('0xff', '');

checkSanitization('+1', '');
checkSanitization(' 10', '');
checkSanitization('10 ', '');
checkSanitization('1,2', '');
checkSanitization('1E', '');
checkSanitization('NaN', '');
checkSanitization('nan', '');
checkSanitization('Inf', '');
checkSanitization('inf', '');
checkSanitization('Infinity', '');
checkSanitization('infinity', '');

// Assume empty string as valid.
check('');

// Huge exponent.
checkSanitization('1.2E65535', '');

// The spec doesn't allow, but our implementation does.
check('1.');
check('1.2e10');

// Disabled
check('invalid', true);
