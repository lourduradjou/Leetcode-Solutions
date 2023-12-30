/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArray = [];
    arr.forEach((element,index) => {
        if(fn(element,index))
            filteredArray.push(element);
    })
    return filteredArray;
};