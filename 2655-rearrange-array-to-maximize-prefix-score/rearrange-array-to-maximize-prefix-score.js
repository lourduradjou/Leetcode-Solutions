/**
 * @param {number[]} nums
 * @return {number}
 */
var maxScore = function(nums) {
    nums.sort((a,b) => b-a)
    let sumOfValues = 0
    let index = 0
    let size = nums.length

    while (index < size) {
        sumOfValues += nums[index]
        if (sumOfValues <= 0)
            return index
        index++
    }

    return size
};