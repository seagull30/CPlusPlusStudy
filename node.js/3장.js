//3.4.2
//const string = 'abc';
//const number = 1;
//const boolean = true;
//const obj = {
//    oustside: {
//        inside: {
//            key: 'value',
//        },
//    },
//};
//console.time('전체시간');

//3.4.3
//const timeout = setTimeout(() => {
//    console.log('1.5초 후 실행');
//}, 1500);
//
//const intervar = setInterval(() => {
//    console.log('1초마다 실행');
//}, 1000);
//
//const timeout2 = setTimeout(() => {
//    console.log('실행되지 않습니다');
//}, 3000);
//
//setTimeout(() => {
//    clearTimeout(timeout2);
//    clearInterval(intervar);
//}, 2500);
//
//const immediate = setImmediate(() => {
//    console.log('즉시 실행');
//});
//
//const immediate2 = setImmediate(() => {
//    console.log('실행되지 않습니다.');
//});
//
//clearImmediate(immediate2);


//const crypto = require('crypto');
//const { isMainThread, parentPort } = require('worker_threads');
//
//const algorithm = 'aes-256-cbc';
//const key = 'abcdefghijklmnopqrstuvwxyz123456';
//const iv = '1234567890123456';
//
//const cipher = crypto.createCipheriv(algorithm, key, iv);
//let result = cipher.update('asd', 'utf8', 'base64');
//result += cipher.final('base64');
//console.log('암호화:', result);
//
//const decipher = crypto.createDecipheriv(algorithm, key, iv);
//let result2 = decipher.update(result, 'base64', 'utf8');
//result2 += decipher.final('utf8');
//console.log('복호화', result2);

//3.5.7 worker_theads

//const {
//    Worker, isMainThread, parentPort,
//} = require('worker_threads');
//
//if (isMainThread) {
//    const worker = new Worker(__filename);
//    worker.on('message', message => console.log('from worker', message));
//    worker.on('exit', () => console.log('worker exit'));
//    worker.postMessage('ping');
//} else {
//    parentPort.on('message', (value) => {
//        console.log('from parent', value);
//        parentPort.postMessage('pong');
//        parentPort.close();
//    });
//}

//const min = 2;
//const max = 10000000;
//const primes = [];
//function generatePrimes(start, range) {
//    let isPrime = true;
//    const end = start + range;
//    for (let i = start; i < end; i++) {
//        for (let j = min; j < Math.sqrt(end); ++j) {
//            if (i != j && i % j === 0) {
//                isPrime = false;
//                break;
//            }
//        }
//        if (isPrime) {
//            primes.push(i);
//        }
//        isPrime = true;
//    }
//}
//
//console.time('prime');
//generatePrimes(min, max);
//console.timeEnd('prime');
//console.log(primes.length);

const { Worker, isMainThread, parentPort, workerData } = require('worker_threads');

const min = 2;
let primes = [];

function FindPrimes(start, range) {
    let isPrime = true;
    const end = start + range;
    for (let i = start; i < end; i++) {
        for (let j = min; j < Math.sqrt(end); ++j) {
            if (i != j && i % j === 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push(i);
        }
        isPrime = true;
    }
}
if (isMainThread) {
    const max = 10000000;
    const threadCount = 8;
    const threads = new Set();
    const range = Math.ceil((max - min) / threadCount);
    let start = min;
    console.time('prime');
    for (let i = 0; i < threadCount - 1; ++i) {
        const wStart = start;
        threads.add(new Worker(__filename, { workerData: { start: wStart, range } }));
        start += range;
    }
    threads.add(new Worker(__filename, { workerData: { start, range: range + ((max - min + 1) % threadCount) } }));
    for (let worker of threads) {
        worker.on('error', (err) => {
            throw err;
        });
        worker.on('exit', () => {
            threads.delete(worker);
            if (threads.size === 0) {
                console.timeEnd('prime');
                console.log(primes.length);
            }
        });
        worker.on('message', (msg) => {
            primes = primes.concat(msg);
        });
    }
} else {
    FindPrimes(workerData.start, workerData.range);
    parentPort.postMessage(primes);
}