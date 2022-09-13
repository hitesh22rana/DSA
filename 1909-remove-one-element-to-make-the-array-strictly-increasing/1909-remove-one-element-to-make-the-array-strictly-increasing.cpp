class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        
        for(int i = 0 ; i<nums.size() ; i++) {
            bool flag = false;
            
            if(i == 0) {
                for(int j = 1 ; j<nums.size() - 1 ; j++) {
                    if(nums[j] >= nums[j+1]) {
                        flag = true;
                        break;
                    }
                } 
            }
            
            else if(i == nums.size() - 1) {
                for(int j = 0 ; j<nums.size() - 2 ; j++) {
                    if(nums[j] >= nums[j+1]) {
                        flag = true;
                        break;
                    }
                }
            }
            
            else {
                for(int j = 0 ; j<nums.size() - 1 ; j++) {
                    if(i == j) continue;
                    
                    else if(j == i-1) {
                        if(j+2 < nums.size() && nums[j] >= nums[j+2]) {
                            flag = true;
                            break;
                        }
                    } else {
                        if(nums[j] >= nums[j+1]) {
                            flag = true;
                            break;
                        }
                    }
                    
                }    
            }
            
            if(!flag) return true;
            
            if(flag) count++;
                    
        }
        
        return count < 2;
    }
};