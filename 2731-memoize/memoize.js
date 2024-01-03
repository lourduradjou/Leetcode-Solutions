/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let dp = {};
    return function(...args) {
        const value = JSON.stringify(args);//passing values not an array so ... is not used

        if(value in dp) {
            return dp[value];
        }
        else {
            let tempValue = fn(...args);
            dp[value] = tempValue;
            return tempValue;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */