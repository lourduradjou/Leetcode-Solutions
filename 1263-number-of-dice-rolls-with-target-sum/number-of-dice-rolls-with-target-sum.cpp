class Solution {
public:

int mod=1e9+7;

int HelperRec(int dices,int faces,int target){

    if(dices< 0) return target==0;

    int ans=0;
    for(int i=1;i<=faces;i++){
        ans+=HelperRec(dices-1,faces,target-i);
    }
    return ans;
}

int HelperMemo(int dices,int faces,int target,vector<vector<int>>&dp){

    if(target< 0) return 0;
    if(dices==0) return target==0;

    if(dp[dices][target]!= -1 ) return dp[dices][target];

    int ans=0;
    for(int i=1;i<=faces;i++){
        ans=(ans+HelperMemo(dices-1,faces,target-i,dp))%mod;
    }
    dp[dices][target]=ans;
    return ans;
}

int HelperTab(int dices,int faces,int target){

    // if(target< 0) return 0;
    // if(dices==0) return target==0;
    vector<vector<int>>dp(dices+1,vector<int>(target+1,0));
    // if(dp[dices][target]!= -1 ) return dp[dices][target];
    dp[0][0]=1;
    int ans=0;
    for(int i=1;i<=dices;i++){
        for(int j=1;j<=target;j++){
            for(int k=1;k<=faces;k++){
                if(j-k >= 0){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
                }
            }
        }
    }

    return dp[dices][target];
}

    int numRollsToTarget(int n, int k, int target) {
        // 1. Recursion
        // return HelperRec(n,k,target); //Gives TLE Error

        // 2.Memorization
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return HelperMemo(n,k,target,dp);

        // 3. Tabulation
        // return HelperTab(n,k,target);

    }
};