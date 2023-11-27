
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int knightDialer(int n) {
        //initialize a vector to store the answers at each iteration and use it for further 2...to n iteration cases
        vector<long long> curPos(10, 1);

        for(int ite = 2; ite <= n; ite++) {
            vector<long long> newPos(10);

            //calculate the position
            newPos[0] = (curPos[6] + curPos[4]) % MOD;
            newPos[1] = (curPos[6] + curPos[8]) % MOD;
            newPos[2] = (curPos[7] + curPos[9]) % MOD;
            newPos[3] = (curPos[4] + curPos[8]) % MOD;
            newPos[4] = (curPos[0] + curPos[3] + curPos[9]) % MOD;
            newPos[5] = 0;
            newPos[6] = (curPos[0] + curPos[1] + curPos[7]) % MOD;
            newPos[7] = (curPos[2] + curPos[6]) % MOD;
            newPos[8] = (curPos[1] + curPos[3]) % MOD;
            newPos[9] = (curPos[2] + curPos[4]) % MOD;
            // newPos[0] = (curPos[6] + curPos[4]) & MOD:
            //after the assigning update the curPos to new values to continue the iteration
            curPos = newPos;
        }

        long long totalCount = 0;
        for(int i = 0; i < 10; i++) {
            totalCount = (totalCount + curPos[i]) % MOD;
        }
        return totalCount;
    }
};