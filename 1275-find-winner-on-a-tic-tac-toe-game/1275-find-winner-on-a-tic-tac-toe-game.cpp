class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3,vector<int>(3,0));
        
        for(int i = 0 ; i<moves.size() ; i++) {
            vector<int>& move = moves[i];
            
            if(i & 1) {
                board[move[0]][move[1]] = 1;
            } else {
                board[move[0]][move[1]] = -1;
            }
        }
        
        int sum = 0;
        
        for(int i = 0 ; i<3 ; i++) {
            sum = 0;
            
            // Vertical Sum
            for(int j = 0 ; j<3 ; j++) {
                sum += board[i][j];    
            }
            
            if(sum == -3) return "A";
            if(sum == 3) return "B";
            
            sum = 0;
            
            // Horizontal Sum
            for(int j = 0 ; j<3 ; j++) {
                sum += board[j][i];
            }
            
            if(sum == -3) return "A";
            if(sum == 3) return "B";
        }
        
        // Diagonal Sum
        int leftDiagonal = board[0][0] + board[1][1] + board[2][2];
        int rightDiagonal = board[0][2] + board[1][1] + board[2][0];
        
        if(leftDiagonal == -3 || rightDiagonal == -3) return "A";
        if(leftDiagonal == 3 || rightDiagonal == 3) return "B";
        
        if(moves.size() < 9) return "Pending";
        
        return "Draw";
    }
};