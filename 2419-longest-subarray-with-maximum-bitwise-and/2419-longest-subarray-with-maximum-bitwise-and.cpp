class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        
        for(int& num : nums) {
            maxi = max(num,maxi);    
        }
        
        int ans = 0;
        int cnt = 0;
        
        for(int i = 0 ; i<nums.size() ; i++) {
            if(nums[i] == maxi) cnt++;
            else cnt = 0;
            ans = max(cnt,ans);
        }
        
        return ans;
    }
};