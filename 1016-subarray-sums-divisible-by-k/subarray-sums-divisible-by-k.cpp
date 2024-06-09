class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int prefixSum = 0, mod = 0;
        unordered_map<int, int> map;
        map[0] = 1;

        for (int num: nums) {
            prefixSum += num;
            mod = prefixSum % k;
            if (mod < 0) mod += k;

            if (map.find(mod) != map.end()) //we found the mod in the map 
            {
                cnt += map[mod];
                map[mod]++;
            }
            else {
                map[mod] = 1;
            }
        }

        return cnt;
    }
};