class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int> > mp;
        
        for(int i = 0 ; i<nums.size() ; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for(auto& it : mp) {
            int n = it.second.size();
            if(n < 2) continue;
            
            for(int i = 1 ; i<n ; i++) {
                if(abs(it.second[i] - it.second[i-1]) <= k) return true;
            }
        }
        
        return false;
    }
};