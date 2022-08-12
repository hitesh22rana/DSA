class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indexes;
        vector<int> ans;
        
        for(int i = 0 ; i<nums.size() ; i++) {
            if(nums[i] == key) {
                indexes.push_back(i);
            }
        }

        for(int i = 0 ; i<nums.size() ; i++) {
            for(int& index : indexes) {
                if(abs(index-i) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        
        return ans;
    }
};