/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    let leftMin = 0, leftMax = 0;

    for (let c of s) {
        if (c === '(') {
            leftMin++;
            leftMax++;
        }
        else if (c === ')') {
            leftMin--;
            leftMax--;
        }
        else {
            leftMin--;
            leftMax++;
        }

        if (leftMin < 0) leftMin = 0;
        if (leftMax < 0) return false;
    }

    return leftMin === 0;
};