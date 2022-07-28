class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() == 0 || t.size() == 0 || s.size() != t.size()) return false;
        unordered_map<char,int> mp;
        
        for(char &c : s) {
            mp[c]++;
        }
        
        for(char &c : t) {
            if(mp.find(c) != mp.end() && mp[c] > 0) {
                mp[c]--;
            } else return false;
        }
        return true;
    }
};