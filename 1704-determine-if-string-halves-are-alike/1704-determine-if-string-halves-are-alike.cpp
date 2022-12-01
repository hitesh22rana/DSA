class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';  
    }
    
public:
    bool halvesAreAlike(string s) {
        int half = s.size()/2;
        
        string str1 = s.substr(0,half);
        string str2 = s.substr(half, s.size());
                        
        int numOfVowel = 0;
        
        for(char& c : str1) {
            char ch = tolower(c);
            if(isVowel(ch)) {
                numOfVowel++;
            }
        }
        
        for(char& c : str2) {
            char ch = tolower(c);
            if(isVowel(ch)) {
                numOfVowel--;
            }
        }
        
        return numOfVowel == 0;
    }
};