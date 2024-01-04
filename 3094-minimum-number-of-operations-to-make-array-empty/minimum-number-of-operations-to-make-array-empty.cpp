class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it: nums) {
            mpp[it]++;
        }
        int count = 0;

        for(auto freq: mpp) {
            int numCnt = freq.second;
            if(numCnt % 3 == 0)
                count += (numCnt / 3);
            else {
                int cntTwos = 0;
                while(numCnt % 3 != 0) {
                    numCnt -= 2;
                    cntTwos++;
                }
                //this loop will make sure to remove the unnecessary twos 
                //then add the three counts
                if(numCnt >= 0 && numCnt % 3 == 0) {
                    //it is pos number and having counts of three so add it 
                    //if is a pos number but not a count of three means either it will 
                    //be two or one ,,if two means numCnt will be zero after the above
                    //while loop so we can just add the twos count to the ans 
                    //else the numCnt is one so return -1 for that.
                    count += numCnt / 3;
                    count += cntTwos;
                }
                else {
                    return -1;
                }
            }
        }

        return count;
    }
};