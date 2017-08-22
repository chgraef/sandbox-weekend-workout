'use strict';

const readline = require('readline');
const sqlite3  = require('sqlite3');

let stdin = readline.createInterface({
    input:  process.stdin,
    output: process.stdout
}).on('close', () => { console.log('Bye bye bye!'); });

stdin.question('What is yer name, mate?\n', (answer) => {
    const db = new sqlite3.Database(':memory:');

    db.serialize(() => {
        const userId   = 0;
        const userName = answer;

        db.run('CREATE TABLE users (id INT, name TEXT)');
        db.run('INSERT INTO users VALUES (?, ?)', userId, userName);

        db.each('SELECT * FROM users', (err, row) => {
            if (err) throw err;
            console.log(row.id, row.name);
        });
    });

    stdin.close();
});
