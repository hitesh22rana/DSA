class Solution {
    int len{0};
public:
    int maxLength(vector<string>& arr) {
        checkLen("", arr, 0);
        return len;
    }
    
    void checkLen(string str, vector<string> &arr, int itr) {
        if (!isUnique(str)) return;
        
        if(str.size() > len) {
            len = str.size();
        }
        
        for (int i = itr ; i<arr.size() ; i++) {
            checkLen(str+arr[i], arr, i+1);            
        }
    }
    
    bool isUnique(string word) {
        vector<bool> st(26);
        
        for(char& c : word) {
            if(st[c - 'a']) return false;
            st[c - 'a'] = true;
        }
        
        return true;
    }
};