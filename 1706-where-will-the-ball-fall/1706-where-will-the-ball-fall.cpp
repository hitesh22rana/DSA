class Solution {
public:
    int canReached(vector<vector<int>>& grid, int row, int col) {
        if(col < 0 || col >= grid[0].size()) return -1;
        
        if(row >= grid.size()) return col;
        
        if(grid[row][col] == 1) {
            if(col + 1 < grid[0].size() && grid[row][col + 1] == -1) return -1;
            return canReached(grid, row+1, col+1);
        }
        
        if(col - 1 >= 0 && grid[row][col - 1] == 1) return -1;
        
        return canReached(grid, row+1, col-1);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans;
        
        for(int i = 0 ; i<n ; i++) {
            int column = canReached(grid, 0, i);
            ans.push_back(column);
        }
        
        return ans;
    }
};