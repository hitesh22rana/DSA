class Solution {
public:
    void dfs(int i , int j , vector<vector<char>>& grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        if(grid[i][j] == '1') {
            grid[i][j] = '0';
        }
        
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};