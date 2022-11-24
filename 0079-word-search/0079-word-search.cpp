class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool check(int i, int j, string word, int index, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        if(index == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || vis[i][j]) return false;
        
        vis[i][j] = true;
        
        for(int k = 0 ; k<4 ; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            
            if(check(newX, newY, word, index + 1, board, vis)) return true;            
        }

        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0 ; i<board.size() ; i++) {
            for(int j = 0 ; j<board[0].size() ; j++) {
                char c = board[i][j];
                if(c == word[0]) {
                    if(check(i, j, word, 0, board, vis)) return true;
                }
            }
        }
        
        return false;
    }
};