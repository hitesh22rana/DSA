class Solution {
public:
    int MOD = 1e9+7;

    int numRollsToTarget(int n, int k, int target) {
        vector<long long int> prev(target + 1);
        vector<long long int> curr(target + 1);
        prev[0] = 1;
        
        for(int dice = 1 ; dice<=n ; dice++) {
            for(int t = 1 ; t<=target ; t++) {
                long long int ans = 0;
                
                for(int i = 1 ; i<=k ; i++) {
                    if(t - i >= 0) {
                        ans = ((ans % MOD) + (prev[t - i] % MOD)) % MOD;                    
                    }
                }
                
                curr[t] = ans;
            }
            
            prev = curr;
        }

        return prev[target];
    }
};