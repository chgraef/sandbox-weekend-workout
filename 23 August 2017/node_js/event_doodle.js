'use strict';

const events = require('events');

const wait = (ms) => {
    const startTime = new Date().getTime();
    const endTime   = startTime + ms;

    while (new Date().getTime() < endTime) {
        continue;
    }
};

class Story {
    constructor(eventEmitter) {
        this.eventEmitter = eventEmitter;
    }

    goHome() {
        this.eventEmitter.emit('goHome');
        wait(4000);
    }

    goSleep() {
        this.eventEmitter.emit('goSleep');
    }

    on() {
        return this.eventEmitter.on(...arguments);
    }

    once() {
        return this.eventEmitter.once(...arguments);
    }
}

let emitter = new events.EventEmitter();
let story   = new Story(emitter);

story
    .on('goHome',  () => { console.log('Going home...'); })
    .on('goSleep', () => { console.log('Going to sleep...'); });

story.goHome();
story.goSleep();
