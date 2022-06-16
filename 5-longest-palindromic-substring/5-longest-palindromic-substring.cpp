class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<bool> > dp(n , vector<bool>(n,false));
        string longest = "";
        int maxi = 0;
        pair<int,int> strIndex;
        
        for(int g = 0 ; g<n ; g++) {
            
            for(int i = 0 , j = g ; j < dp[0].size() ; i++ , j++) {
                if(g == 0) {
                    dp[i][j] = true;
                } else if(g == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if(s[i] == s[j] && dp[i+1][j-1] == true) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }
                
                if(dp[i][j]) {
                    if(j-i+1 > maxi) {
                        maxi = j-i+1;
                        strIndex.first = i;
                        strIndex.second = j-i+1;
                    }
                }   
            }
        }
        return s.substr(strIndex.first,strIndex.second);
    }
};