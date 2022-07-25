class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums(arr.begin(),arr.end());
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        
        for(int num : nums) {
            mp.emplace(num, mp.size() + 1);
        }
        
        for(int i = 0 ; i<arr.size() ; i++) {
            nums[i] = mp[arr[i]];
        }
        
        return nums;
    }
};