class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        
        for(int& num : nums) {
            if(!(num&1)) sum += num;
        }
        
        for(vector<int>& query : queries) {
            int index = query[1];
            int val = query[0];
            
            if(nums[index] & 1) {
                nums[index] += val;
                
                if(!(nums[index] & 1)) {
                    sum += nums[index];
                }
                
            } else {
                int temp = nums[index];
                nums[index] += val;
                
                if(nums[index] & 1) {
                    sum -= temp;
                } else {
                    sum += nums[index] - temp;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};