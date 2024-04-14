/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
        let reachableDistance = 0;
        let nextReachable = 0;

        for (let i = 0; i < nums.length; i++) {
            if (i > reachableDistance) return false;
            nextReachable = i + nums[i];
            reachableDistance = Math.max(reachableDistance, nextReachable);
        }

        return true;
};