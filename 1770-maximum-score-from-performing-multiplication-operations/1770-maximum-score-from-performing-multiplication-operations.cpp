class Solution {
public:
    int helper(vector<int>& nums, vector<int>& multipliers, int start, int end, int pos, vector<vector<int>>& dp) {
        if(pos == multipliers.size()) return 0;
        
        if(dp[pos][start] != INT_MIN) return dp[pos][start];
        
        int left = nums[start] * multipliers[pos] + helper(nums,multipliers,start+1,end,pos+1,dp);
        int right = nums[end] * multipliers[pos] + helper(nums,multipliers,start,end-1,pos+1,dp);
        
        return dp[pos][start] = max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size()+1,vector<int>(multipliers.size()+1,INT_MIN));
        return helper(nums,multipliers,0,nums.size()-1,0,dp);
    }
};