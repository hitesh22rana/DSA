class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        int ans = 1;
        
        for(int i = 2 ; i<=n ; i++) {
            if(i&1) {
                dp[i] = dp[i/2] + dp[i/2 + 1];
            } else {
                dp[i] = dp[i/2];
            }
            ans = max(dp[i],ans);
        }
        
        return ans;
    }
};