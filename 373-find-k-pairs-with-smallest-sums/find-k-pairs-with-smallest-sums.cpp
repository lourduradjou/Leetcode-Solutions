class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;

        for (int i = 0; i < nums1.size(); i++) {
            pq.push( {nums1[i] + nums2[0], 0} );
        }

        while (k-- &&  !pq.empty()) {
            int sum = pq.top().first;
            int secondArray_pos = pq.top().second;

            ans.push_back( {sum - nums2[secondArray_pos], nums2[secondArray_pos]} );
            pq.pop();

            if (secondArray_pos + 1 < nums2.size()) {
                pq.push( {sum - nums2[secondArray_pos] + nums2[secondArray_pos + 1], secondArray_pos + 1} );
            }

        }

        return ans;
    }
};