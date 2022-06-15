class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > total;
        int n = nums.size();
        if(n < 4) return total;
        sort(nums.begin() , nums.end());
        
        if((long)nums[n-4] + (long)nums[n-3] + (long)nums[n-2] + (long)nums[n-1] < (long)target) return total;
        
        for(int i = 0 ; i<n-3 ; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if((long)nums[i] + (long)nums[i+1] + (long)nums[i+2] + (long)nums[i+3]>target) break;
            if((long)nums[i] + (long)nums[n-3] + (long)nums[n-2] + (long)nums[n-1]<target) continue;
            
            for(int j = i+1 ; j<n-2 ; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if((long)nums[i] + (long)nums[j] + (long)nums[j+1] + (long)nums[j+2] > target) break;
                if((long)nums[i] + (long)nums[j] + (long)nums[n-2] + (long)nums[n-1] < target) continue;
                int left = j+1 , right = n-1;
                
                while(left < right) {
                    int sum = (long)nums[left] + (long)nums[right] + (long)nums[i] + (long)nums[j];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else {
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do {
                            left++;
                        } while((long)nums[left] == (long)nums[left-1] && left < right);
                        do {
                            right--;
                        } while((long)nums[right] == (long)nums[right+1] && left < right);
                    }
                }
            }
            
        }
        return total;
    }
};