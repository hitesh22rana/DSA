class Solution {
public:
    bool matrixCheck(vector<vector<char>>& board , int n , int m) {
        char c = board[n][m];
        int nx = n/3 * 3;
        int ny = m/3 * 3;
        for(int i = 0 ; i<3 ; i++) {
            for(int j = 0 ; j<3 ; j++) {
                if(i + nx != n && j + ny != m && board[i + nx][j + ny] == c) return false;
            }
        }
        return true;
    }
    
    bool verticalCheck(vector<vector<char>>& board , int row , int column) {
        char c = board[row][column];
        for(int i = 0 ; i<9 ; i++) {
            if(row != i && board[i][column] == c) return false;
        }
        return true;
    }
    
    bool horizontalCheck(vector<vector<char>>& board , int row , int column) {
        char c = board[row][column];
        for(int i = 0 ; i<9 ; i++) {
            if(column != i && board[row][i] == c) return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i<9 ; i++) {
            for(int j = 0 ; j<9 ; j++) {
                if(board[i][j] != '.') {
                    if(!matrixCheck(board , i , j)) return false;
                    if(!verticalCheck(board , i , j)) return false;
                    if(!horizontalCheck(board , i , j)) return false;   
                }
            }
        }
        return true;
    }
};