/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let item = []
    for(let i = 0; i < arr.length; i++) {
        item.push(fn(arr[i], i));
    }
    return item;
};