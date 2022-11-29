class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int ans = 0;
        int sum = 0;
        bool found = false;
        
        for(int& num : nums) {
            if(num < k) sum--;
            else if(num > k) sum++;
            else {
                found = true;   
            }
            
            if(found) {
                if(mp.find(sum) != mp.end()) {
                    ans += mp[sum];
                }
                
                if(mp.find(sum - 1) != mp.end()) {
                    ans += mp[sum - 1];
                }
            } else {
                mp[sum]++;
            }            
        }
    
        return ans;
    }
};