class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size()+1,vector<int>(multipliers.size()+1,0));
        
        for(int start = multipliers.size() - 1 ; start >= 0 ; start--) {
            for(int left = start ; left >= 0 ; left--) {
                dp[start][left] = max(multipliers[start] * nums[left] + dp[start + 1][left + 1], multipliers[start] * nums[nums.size() - 1 - (start - left)] + dp[start + 1][left]);
            }
        }
        
        return dp[0][0];
    }
};