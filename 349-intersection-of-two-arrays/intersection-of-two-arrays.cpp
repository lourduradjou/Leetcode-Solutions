class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //optimal is if equal put into the vector
        //if not equal and less move the i
        //else move the j
        //finally return the duplicates removed vector

        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else 
                j++;
        }
        //remove the consecutive duplicates using unique
        ans.erase( unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};