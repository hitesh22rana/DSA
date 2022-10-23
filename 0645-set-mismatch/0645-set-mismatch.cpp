class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans(2,0);
        
        for(int& num : nums) {
            mp[num]++;
        }
        
        int num = 1;
        for(int i = 0 ; i<=mp.size() ; i++) {
            if(mp.find(num) == mp.end()) {
                ans[1] = num;
            } else {
                if(mp[num] > 1) ans[0] = num;
            }
            num++;
        }
        
        return ans;
    }
};