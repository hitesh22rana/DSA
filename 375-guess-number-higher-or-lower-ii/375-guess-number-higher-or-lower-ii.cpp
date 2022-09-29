class Solution {
public:
    int dp[201][201];
    
    int dfs(long long int n, long long int l, long long int r) {
        if(l == r) return 0;
        
        if(dp[l][r]) return dp[l][r];
        
        long long int ans = INT_MAX;
        
        for(long long int i = l ; i<=r ; i++) {
            long long int t1 = 0, t2 = 0, t3 = 0;
            
            t1 = i;
            
            if(i > 1) {
                t2 = i + dfs(n, l, i-1);
            }
            
            if(i < n) {
                t3 = i + dfs(n , i+1, r);
            }
            
            ans = min(ans,max({t1,t2,t3}));
        }
        
        return dp[l][r] = ans;
    }
    
    int getMoneyAmount(int n) {
        return dfs(n ,1 ,n);
    }
};