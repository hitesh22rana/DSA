class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return false;
        
        int first = INT_MAX;
        int second = INT_MAX;
        
        for(int i = 0 ; i<n ; i++) {
            if(nums[i] < first) {
                first = nums[i];
            }
            
            else if(first < nums[i] && nums[i] < second) {
                second = nums[i];
            }
            
            else if(nums[i] > second) {
                return true;
            }
        }
        
        return false;
    }
};