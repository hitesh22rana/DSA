class Solution {
public:
    string reverseVowels(string s) {
        queue<char> q;
        
        for(char& c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                q.push(c);
            }
        }
        
        for(int i = s.size() - 1 ; i>=0 ; i--) {
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                s[i] = q.front();
                q.pop();
            }
        }
        
        return s;
    }
};