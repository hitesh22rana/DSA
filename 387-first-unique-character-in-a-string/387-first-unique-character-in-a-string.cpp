class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,0);
        
        for(char& c : s) {
            count[c-'a']++;
        }
        
        for(int i = 0 ; i<s.size() ; i++) {
            char c = s[i];
            if(count[c-'a'] <= 1) return i;
        }
        
        return -1;
    }
};