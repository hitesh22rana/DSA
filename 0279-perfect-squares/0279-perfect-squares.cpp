class Solution {
public:
    long long int findPerfectSquares(int n, vector<int>& dp) {
        if(n <= 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        long long int mini = INT_MAX;
        
        for(int i = 1 ; i*i<=n ; i++) {
            long long int val = 1 + findPerfectSquares(n - i*i, dp);
            mini = min(mini, val);
        }
        return dp[n] = mini;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return findPerfectSquares(n, dp);
    }
};