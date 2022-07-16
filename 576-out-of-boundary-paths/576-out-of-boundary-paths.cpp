class Solution {
public:
    int mod = pow(10,9) + 7;
    
    long long int helperFunction(int row, int col, int maxMoves, int x, int y,  int moves, vector<vector<vector<long long int>>> & dp){
        if(x < 0 || y < 0 || x >= row || y >= col){
            return 1;
        }
        if(moves == maxMoves){
            return 0;
        }
        if(dp[moves][x][y] != -1){
            return dp[moves][x][y] % mod;
        }

        return dp[moves][x][y] = ((helperFunction(row, col, maxMoves, x, y - 1, moves + 1, dp) % mod) + (helperFunction(row, col, maxMoves, x - 1, y, moves + 1, dp) % mod) + (helperFunction(row, col, maxMoves, x + 1, y, moves + 1, dp) % mod) + (helperFunction(row, col, maxMoves, x, y + 1, moves + 1, dp) % mod)) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long int>>> dp(maxMove + 1, vector<vector<long long int>> (m + 1, vector<long long int> (n + 1, -1)));
        dp[maxMove][m][n] = helperFunction(m, n, maxMove, startRow, startColumn, 0, dp);
        return dp[maxMove][m][n];
    }
};