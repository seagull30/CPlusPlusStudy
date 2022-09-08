if (true) {
    var x = 3;
}
console.log(x);

var num1 = 1;
var num2 = 2;
var result = 3;
var string1 = num1 + `더하기` + num2 + `는\`` + result + `\``;
console.log(string1);

var num3 = 1;
var num4 = 2;
var result2 = 3;
var string2 = `${num3} 더하기 ${num4} 는 '${result}'`;
console.log(string2);

var saynode = function () {
    console.log('node');
};
var es = 'ES';

var oldObject = {
    sayJS: function () {
        console.log('JS');
    },
    saynode: saynode,
};
oldObject[es + 6] = 'fantastic';
oldObject.saynode();
oldObject.sayJS();
console.log(oldObject.ES6);

const NewObject = {
    sayJS() {
        console.log('JS');
    },
    saynode,
    [es + 6]: 'Fantastic',
};
NewObject.saynode();
NewObject.sayJS();
console.log(NewObject.ES6);

function add1(x, y) {
    return x + y;
}
const add2 = (x, y) => {
    return x + y;
};
const add3 = (x, y) => x + y;
const add4 = (x, y) => (x + y);

function not1(x) {
    return !x;
}
const not2 = x => !x;

var relationship1 = {
    name: 'zero',
    friends: ['nero', 'hero', 'xero'],
    logFriends: function () {
        var that = this;
        this.friends.forEach(function (friend) {
            console.log(that.name, friend);
        });
    },
};

relationship1.logFriends();

const candyMachine = {
    status: {
        name: 'node',
        count: 5,
    },
    getCandy() {
        this.status.count--;
        return this.status.count;
    },
};
const { getCandy, status: { count } } = candyMachine;

// 2.1.7
const condition = true;
const promise = new Promise((resolve, reject) => {
    if (condition) {
        resolve('성공');
    } else {
        reject('실패');
    }
});
promise
    .then((message) => {
        console.log(message);
    })
    .catch((error) => {
        console.error(error);
    })
    .finally(() => {
        console.log('무조건');
    })

const promise1 = Promise.resolve('성공1');
const promise2 = Promise.resolve('성공2');
Promise.all([promise1, promise2])
    .then((result) => {
        console.log(result);
    })
    .catch((error) => {
        console.error(error);
    })
