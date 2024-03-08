class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int it: nums) 
            mp.put(it, mp.getOrDefault(it, 0) + 1);
        
        int maxi = 0;
        for (int it: mp.values()) {
            maxi = Math.max(maxi, it);
        }

        int ans = 0;
        for (int it: mp.values())
        {
            if (it == maxi)
                ans += maxi;
        }

        return ans;
    }
}