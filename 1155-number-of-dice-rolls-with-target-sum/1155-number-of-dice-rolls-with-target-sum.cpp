class Solution {
public:
    int MOD = 1e9+7;
    int dpMem(int dice, int k, int target, vector<vector<long long int>>& dp) {
        if(target < 0) return 0;
        
        if(dice == 0 && target != 0) return 0;
        
        if(target == 0 && dice != 0) return 0;
        
        if(dice == 0 && target == 0) return 1;
        
        if(dp[dice][target] != -1) return dp[dice][target];
        
        long long int ans = 0;
        for(int i = 1 ; i<=k ; i++) {
            ans = (ans % MOD + dpMem(dice - 1, k, target - i, dp) % MOD) % MOD;
        }
        
        return dp[dice][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(target+1,-1));
        return dpMem(n,k,target,dp);
    }
};