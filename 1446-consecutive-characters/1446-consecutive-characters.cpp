class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int maxi = 0;
        int n = s.size();
        int i = 1;
        
        while(i < n) {
            if(s[i] != s[i-1]) {
                maxi = max(count,maxi);
                count = 1;
            } else {
                count++;
            }
            i++;
        }
        return max(count,maxi);
    }
};