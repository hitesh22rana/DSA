class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 1) return 1;
        bool flag = s == string(s.rbegin(), s.rend());
        return flag ? 1 : 2;
    }
};