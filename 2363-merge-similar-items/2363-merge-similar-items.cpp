class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int> mp;
        
        for(vector<int>& item : items1) {
            mp[item[0]] += item[1];
        }
        
        for(vector<int>& item : items2) {
            mp[item[0]] += item[1];
        }
        
        vector<vector<int>> ans;
        
        for(auto& it : mp) {
            ans.push_back({it.first,it.second});
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};