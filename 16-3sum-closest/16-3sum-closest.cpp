class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        for(int first = 0 ; first < n - 2 ; first++) {
            if(first > 0 && nums[first] == nums[first-1]) continue;
            
            int second = first+1;
            int third = n-1;
            
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                
                if(sum == target) return sum;
                
                if(abs(target-sum)<abs(target-closest)) {
                    closest = sum;
                }
                
                else if(sum < target) {
                    second++;
                }
                
                else {
                    third--;
                }
            }
            
        }
        
        return closest;
    }
};