class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string st1;
        string st2;
        
        for(string& word : word1) {
            st1 += word;
        }
        
        for(string& word : word2) {
            st2 += word;
        }
        
        return st1 == st2;
    }
};