'use strict';

const round = (x, prec = 1) => {
    const sign   = x >= 0 ? 1 : -1;
    const value  = Math.abs(x);
    const exp    = Math.pow(10, prec);
    const result = Math.floor(0.5 + value * exp) / exp;

    return sign * result;
};

const round_to_half = (x) => {
    const sign = x >= 0 ? 1 : -1;
    return sign * Math.floor(Math.abs(2 * x) + 0.5) / 2;
};

const showValues = (kwargs) => {
    const argNames = Object.keys(kwargs);

    const argPairs = argNames.map((name) => {
        const value = kwargs[name];
        return `${name} = ${value}`;
    });

    console.log(...argPairs);
};

function* count({ start = 0, step = 1 })
{
    for (let value = start; ; value += step) {
        yield value;
    }
}

function* takeWhile({ predicate, iterable })
{
    for (const value of iterable)
    {
        const canTakeThis = predicate(value);

        if (canTakeThis) {
            yield value;
        } else {
            break;
        }
    }
}

function* map({ processor, iterable })
{
    for (const value of iterable) {
        const result = processor(value);
        yield result;
    }
}

function* validStates()
{
    let range = count({ step: 0.2 });

    let validRange = takeWhile({
        predicate: (x) => x <= 1.0,
        iterable: range
    });

    let states = map({
        processor: (p) => {
            const q = 1 - p;
            return { p, q };
        },
        iterable: validRange
    });

    for (const state of states) yield state;
}

for (const state of validStates()) {
    showValues(state);
}
