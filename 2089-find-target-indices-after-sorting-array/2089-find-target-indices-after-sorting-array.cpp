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
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int low = lowIndex(nums,target);
        int high = highIndex(nums,target);
        
        vector<int> ans;
        
        if(low == -1 || high == -1) return ans;
        
        for(int indx = low ; indx<=high ; indx++) ans.push_back(indx);
        return ans;
    }
};