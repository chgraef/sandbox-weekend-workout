function generateRandomInteger(max = 4294967295) {
    const randFloat = max * Math.random();
    const randInt   = Math.floor(randFloat);

    return randInt;
}

function makeRandomChoice(values) {
    const length     = values.length;
    const randIndex  = generateRandomInteger(length);
    const randChoice = values[randIndex];

    return randChoice;
}

function generateRandomChar() {
    const BASE     = 'abcdefghijklmnopqrstuvwxyz';
    const randChar = makeRandomChoice(BASE);

    return randChar;
}

function range(start, stop, step = 1) {
    const count = Math.floor((stop - start) / step);
    let  result = [];

    for (let value = start; value < stop; value += step) {
        result.push(value);
    }

    return result;
}

function generateRandomString() {
    const MAX_LENGTH = 32;

    const length = generateRandomInteger(max = MAX_LENGTH);
    let   result = range(0, length).map(generateRandomChar).join('');

    return result;
}

const count = 64;

for (let times = 0; times < count; ++times) {
    const randString = generateRandomString();
    console.log(randString);
}

