class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        
        for(int& num : nums) {
            mp[num]++;
        }        
        
        for(int& num : nums) {
            if(mp[num] <= 0) continue;

            for(int start = num ; start<num+k ; start++) {
                if(mp[start] <= 0) return false;
                mp[start]--;
            }
            
        }
        
        return true;
    }
};