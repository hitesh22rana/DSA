class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string st1;
        string st2;
        
        for(string& word : word1) {
            for(char& c : word) st1.push_back(c);
        }
        
        for(string& word : word2) {
            for(char& c : word) st2.push_back(c);
        }
        
        return st1 == st2;
    }
};