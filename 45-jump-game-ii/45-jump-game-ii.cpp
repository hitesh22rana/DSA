class Solution {
public:
    int minJumps(vector<int>& nums, vector<int>& dp, int index) {
        if(index >= nums.size()-1) return 0; 
        
        if(dp[index] != 10001) return dp[index];
        
        for(int j = 1 ; j<= nums[index] ; j++) {
            dp[index] = min(1 + minJumps(nums,dp,j+index), dp[index]);
        }
        
        return dp[index];
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),10001);
        return minJumps(nums,dp,0);
    }
};