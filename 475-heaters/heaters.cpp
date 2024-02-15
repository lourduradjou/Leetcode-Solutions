class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        /* two pointer */
		int i = 0, j = 0;
		int ans;
		vector<int> arr(houses.size(), INT_MAX);
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		for (i = 0; i < houses.size(); i++) {
			while (j + 1 < heaters.size() && houses[i] >= heaters[j]) {
				j++;
			}
			if (j - 1 >= 0) // initial case if it is not moved
				arr[i] = min(abs(houses[i] - heaters[j-1]), abs(houses[i] - heaters[j]));
			else
				arr[i] = abs(houses[i] - heaters[j]);
		}
        
        ans = arr[0];
		for (i = 1; i < arr.size(); i++)
			ans = max(ans, arr[i]);
		return ans;
    }
};