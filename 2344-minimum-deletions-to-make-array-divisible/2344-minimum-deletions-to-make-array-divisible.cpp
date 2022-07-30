class Solution {
public:   
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int len = numsDivide.size();
        
        for(int i = 0 ; i<n ; i++) {
            int num = nums[i];
            bool flag = false;
            
            for(int j = 0 ; j<len ; j++) {
                if(numsDivide[j] % num != 0) {
                    flag = true;
                    break;
                } 
            }    
            
            if(flag) {
                ans++;
                
                while(i+1 < n && num == nums[i+1]) {
                    i++;
                    ans++;
                }
                
            }
            
            else {
                return ans;   
            }
        }
        
        return -1;
    }
};