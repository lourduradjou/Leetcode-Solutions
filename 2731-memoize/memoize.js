/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let dp = {};
    return function(...args) {
        const value = JSON.stringify(args);//passing values not an array so ... is not used
        if(dp[value] === undefined) {
            dp[value] = fn(...args);
        }
        return dp[value];
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