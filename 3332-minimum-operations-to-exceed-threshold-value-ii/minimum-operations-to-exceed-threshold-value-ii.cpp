typedef long long int ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<ll> st;
        int cnt = 0;

        for (auto it: nums)
            st.insert(it);
        
        while (st.size() >= 2) {
            ll val1 = *st.begin();
            st.erase(st.begin());
            //removes the first min element without deleting the duplicated;
            if (val1 >= k) break;

            ll val2 = *st.begin();
            st.erase(st.begin());

            ll addNum = val1 * 2 + val2;
            st.insert(addNum);
            cnt++;
        }

        return cnt;
    }
};