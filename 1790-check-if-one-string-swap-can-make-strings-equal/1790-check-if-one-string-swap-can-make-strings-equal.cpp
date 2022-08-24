class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,char> mp;
        int count = 0;
        
        for(int i = 0 ; i<s1.size() ; i++) {
            if(s1[i] != s2[i]) {
                if(mp.size() > 2) return false;
                
                else if(mp.size() == 1) {
                    if(mp[s2[i]] != s1[i]) return false;
                } 
                count++;
                mp[s1[i]] = s2[i];
            }
        }
        
        return count == 0 || count == 2;
    }
};