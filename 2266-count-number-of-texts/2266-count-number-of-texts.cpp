class Solution {
public:
    int MOD = 1e9+7;
    
    int countNumbers(string& str, int idx, vector<int>& dp) {
        if(idx == str.size()) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int maxPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
        
        long long int currIdx = idx, pressFreq = 1, ans = 0;
        
        while(pressFreq <= maxPress && str[currIdx] == str[idx]) {
            pressFreq++;
            currIdx++;
            ans += countNumbers(str, currIdx, dp) % MOD;
        }
        
        return dp[idx] = ans % MOD;
    }
    
    int countTexts(string pressedKeys) {
        vector<int> dp(100005, -1);
        return countNumbers(pressedKeys, 0, dp) % MOD;
    }
};