class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0 ; i<n-2 ; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int toFind = 0 - nums[i];
                int j = i+1;
                int k = n-1;

                while(j < k) {
                    if(nums[j] + nums[k] == toFind) {
                        ans.push_back({nums[i],nums[j],nums[k]});
                        while(j < k && nums[j] == nums[k-1]) k--;
                        while(j < k && nums[j] == nums[j+1]) j++;
                        
                        j++;
                        k--;
                    }

                    else if(nums[j] + nums[k] < toFind) {
                        j++;
                    }

                    else {
                        k--;
                    }
                }
            }
        }
        
        return ans;
    }
};