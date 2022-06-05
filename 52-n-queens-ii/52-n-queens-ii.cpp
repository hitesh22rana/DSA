class Solution {
private:
    void solve(vector<vector<char>>& chess , int row , int& ans) {
        if (row == chess.size()) {
            ans++;
            return;
        }
        
        for (int col = 0 ; col<chess.size(); col++) {
            if (valid(chess, row, col)) {
                chess[row][col] = 'Q';
                solve(chess, row + 1 , ans);
                chess[row][col] = '.';
            }
        }
    }
    
    bool valid(vector<vector<char>>& chess , int row , int col) {
        // check all cols
        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q') {
                return false;
            }
        }
        //check 45 degree
        for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        //check 135
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
public:
    int totalNQueens(int n) {
        vector<vector<char>> chess(n , vector<char> (n,'.')); 
        int ans = 0;
        solve(chess,0,ans);
        return ans;
    }
};