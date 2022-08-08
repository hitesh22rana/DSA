class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        
        dp[0] = 1;
        int ans = 1;
        
        for(int i = 1 ; i<nums.size() ; i++) {
            int maxi = 0;
            for(int j = 0 ; j<i ; j++) {
                if(nums[j] < nums[i]) {
                    maxi = max(maxi,dp[j]);
                }
            }
            dp[i] = maxi+1;
            if(dp[i] > ans) ans = dp[i];
        }

        return ans;
    }
};