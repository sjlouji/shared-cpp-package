const { performance } = require('perf_hooks');
const addon = require('./build/Release/fft.node');
const calculateRate = require('./rate_calculator/rate_calculator');
const contracts = [10, 20, 30, 40, 50]; // Example contract values

const startJs = performance.now();
const rate = calculateRate(contracts);
const endJs = performance.now();
const timeJs = endJs - startJs;

const startNative = performance.now();
const nativeRate = addon.calculateRate(contracts);
const endNative = performance.now();
const timeNative = endNative - startNative;

console.log(`The calculated JavaScript rate is: ${rate}`);
console.log(`JavaScript execution time: ${timeJs.toFixed(4)} milliseconds`);

console.log(`The calculated Native rate is: ${nativeRate}`);
console.log(`Native execution time: ${timeNative.toFixed(4)} milliseconds`);