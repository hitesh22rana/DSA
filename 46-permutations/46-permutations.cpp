class Solution {
private:
    void permute(vector<int>& nums, int begin , vector<vector<int>>& ans) {
    if(begin >= nums.size()) {
        ans.push_back(nums);
        return;
    }
        
    for(int i = begin ; i<nums.size(); i++) {
        swap(nums[begin],nums[i]);
        permute(nums,begin+1,ans);
        swap(nums[begin],nums[i]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        permute(nums,0,ans);
        return ans;
    }
};