class Solution {
public:
    int lowIndex(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid;
        int ans = -1;
        
        while(s <= e) {
            mid = s + (e-s)/2;    
            if(nums[mid] == target) {
                e = mid-1;
                ans = mid;
            } else if(nums[mid] < target) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        
        return ans;
    }
    
    int highIndex(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid;
        int ans = -1;
        
        while(s <= e) {
            mid = s + (e-s)/2;    
            if(nums[mid] == target) {
                s = mid+1;
                ans = mid;
            } else if(nums[mid] < target) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lowIndex(nums,target);
        int high = highIndex(nums,target);
        return {low,high};
    }
};