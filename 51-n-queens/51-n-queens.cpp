class Solution {
private:
    void solve(vector<vector<string>>& ans , vector<vector<char>>& chess , int row) {
        if (row == chess.size()) {
            ans.push_back(construct(chess));
            return;
        }
        
        for (int col = 0 ; col<chess.size(); col++) {
            if (valid(chess, row, col)) {
                chess[row][col] = 'Q';
                solve(ans, chess, row + 1);
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
    
    vector<string> construct(vector<vector<char>>& chess) {
        vector<string> path;
        for (vector<char> val : chess) {
            string str;
            for(char c : val) {
                str.push_back(c);
            }
            path.push_back(str);
        }
        return path;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> chess(n , vector<char> (n,'.')); 
        vector<vector<string>> ans;
        solve(ans,chess,0);
        return ans;
    }    
};