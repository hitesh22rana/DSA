class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        
        for(int i = 0, j = 0 ; i<nums.size() ; i++) {
            while(j < nums.size() && (nums[j] != key || j < i - k)) j++;
            if(j == nums.size()) break;
            if(i <= j + k && i >= j - k) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};