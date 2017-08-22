'use strict';

const events = require('events');

class MyEmitter extends events.EventEmitter {
    hello() {
        this.emit('hello');
    }
}

let emitter = new MyEmitter()
    .on('hello', () => { console.log('Hi!'); });

emitter.hello();
