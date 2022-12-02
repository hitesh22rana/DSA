class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        if(n1 != n2) return false;
        
        unordered_map<char,int> mp1, mp2;
        unordered_map<int,vector<char>> freq;
        
        for(int i = 0 ; i<n1 ; i++) {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        
        for(auto it : mp2) {
            freq[it.second].push_back(it.first);
        }
        
        for(auto it : mp1) {
            char ch = it.first;
            int count = it.second;
            
            if(mp2.find(ch) == mp2.end()) return false;
            
            if(count != mp2.count(ch)) {
                if(freq[count].size() > 0) {
                    freq[count].pop_back();
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};