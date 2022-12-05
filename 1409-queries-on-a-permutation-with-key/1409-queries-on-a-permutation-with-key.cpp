class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        
        unordered_map<int,int> mp;
        vector<int> nums(m, 0);        
        
        for(int i = 0 ; i<m ; i++) {
            nums[i] = i+1;
        }
        
        for(int i = 1 ; i<=m ; i++) {
            mp[i] = i-1;
        }
        
        for(int& query : queries) {
            int index = mp[query];
            ans.push_back(index);
            
            for(int i = index-1 ; i>=0 ; i--) {
                mp[nums[i]] = i+1;
                swap(nums[i], nums[i+1]);
            }
            
            nums[0] = query;
            mp[query] = 0;
        }
        
        return ans;
    }
};