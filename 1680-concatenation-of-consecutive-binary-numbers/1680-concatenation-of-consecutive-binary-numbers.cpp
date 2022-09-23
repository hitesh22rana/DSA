class Solution {
public:
    int MOD = 1e9+7;
    int concatenatedBinary(int n) {
        long long int ans = 0;
        int digits = 0;
        
        for(int i = 1 ; i<=n ; i++) {
            if(!(i & (i-1))) {
                digits++;
            }    
            
            ans = ((ans << digits) + i) % MOD;
        }
        
        return ans;
    }
};