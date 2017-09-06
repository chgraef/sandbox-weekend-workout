'use strict';

const makePartial = (func, ...args) => {
    return (...innerArgs) => func(...args, ...innerArgs);
};

const logStuff = makePartial(console.log, '>>', ':');

logStuff('Ave', 'Flavius!');
logStuff('Hax', 1337);
