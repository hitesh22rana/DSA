class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        
        int center = nums[nums.size()/2];
        
        int ans = 0;
        
        for(int &val : nums) {
            ans += abs(center - val);
        }
        
        return ans;
    }
};