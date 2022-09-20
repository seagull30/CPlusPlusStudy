const { parse } = require('path');
const url = require('url');

const { URL } = url;
const myurl = new URL('http://www.gilbut.co.kr/book/booklist.aspx?sercate1=001001000#anchor');
console.log('new URL():', myurl);
console.log('url.format():', url.format(myurl));
console.log('------------------------------------------');

const parsedUrl = url.parse('http://www.gilbut.co.kr/book/booklist.aspx?sercate1=001001000#anchor');
console.log('url.parse():', parsedUrl);
console.log('url.format():', url.format(parsedUrl))
