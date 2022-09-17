class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> mp(26,-1);
        
        for(int i = 0 ; i<s.size() ; i++) {
            char c = s[i];
            if(mp[c-'a'] != -1) {
                int val = i - mp[c-'a'] - 1;
                if(val != distance[c-'a']) return false;
            } else {
                mp[c-'a'] = i;
            }
        }
        
        return true;
    }
};