class Solution {
public:
    string greatestLetter(string s) {
        vector<pair<bool,bool>> arr(26);
        map<char,int> mp;
        
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                arr[c-'a'].first = true;
            } else {
                arr[c-'A'].second = true;
            }
            mp[toupper(c)]++;
        }
        
        string str;
        
        for(auto itr : mp) {
            char c = itr.first;
            if(arr[c-'A'].first && arr[c-'A'].second) {
                string st;
                st += c;
                str = st;
            }
        }
        return str;
    }
};