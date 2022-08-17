class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        vector<string> map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string& word : words) {
            string s;
            for(char& c : word) {
                s += map[c-'a'];
            }
            st.insert(s);
        }
        
        return st.size();
    }
};