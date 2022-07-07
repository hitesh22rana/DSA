class Solution {
    public boolean solve(String s1, String s2, String s3, int i, int j, Boolean[][] dp) {
        if(i == s1.length() && j == s2.length()) return true;
        
        if(dp[i][j] != null) return dp[i][j];
        
        if(i < s1.length() && s1.charAt(i) == s3.charAt(i+j)) {
            boolean ans = solve(s1,s2,s3,i+1,j,dp);
            dp[i][j] = ans;
            if(ans) {
                return true;
            }
        }
        
        if(j < s2.length() && s2.charAt(j) == s3.charAt(i+j)) {
            boolean ans = solve(s1,s2,s3,i,j+1,dp);
            dp[i][j] = ans;
            if(ans) {
                return true;
            }
        }
        
        return dp[i][j] = false;
    }
    
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s1.length();
        int m = s2.length();
        
        if(n+m != s3.length()) return false;
        
        return solve(s1,s2,s3,0,0,new Boolean[n+1][m+1]);
    }
}