class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0 ; i<nums.size() ; i++) {
            auto it = mp.find(target - nums[i]);
            
            if(it != mp.end() && it->second != i) return {it->second,i};
            
            mp[nums[i]] = i;
        }
        
        return {-1,-1};
    }
};