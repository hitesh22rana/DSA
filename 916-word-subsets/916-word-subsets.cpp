class Solution {
public:
    bool check(string& word, unordered_map<char,int> mp) {
        vector<int> count(26,0);
        for(char& c : word) {
            count[c-'a']++;
        }
        
        for(auto& it : mp) {
            if(count[it.first-'a'] < mp[it.first]) return false;
        }
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        unordered_map<char,int> mp;
        
        for(string& word : words2) {
            unordered_map<char,int> localCount;
            
            for(char& c : word) {
                localCount[c]++;
            }
            
            for(auto& it : localCount) {
                mp[it.first] = max(mp[it.first],it.second);
            }
            
        }
        
        for(string& word : words1) {
            if(check(word,mp)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};