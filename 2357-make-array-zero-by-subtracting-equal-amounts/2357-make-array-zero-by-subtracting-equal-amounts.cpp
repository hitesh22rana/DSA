class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int& val : nums) {
            if(val != 0) mp[val]++;
        }
        
        return mp.size();
    }
};