class Solution {
private:
    int dfs(vector<vector<int>>& grid , int m , int n , int i , int j , int steps , int s) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return 0;
        if(grid[i][j] == 2) return steps == s ? 1 : 0;
        grid[i][j] = -1;
        int paths = dfs(grid,m,n,i-1,j,steps,s+1) + dfs(grid,m,n,i,j-1,steps,s+1) + dfs(grid,m,n,i+1,j,steps,s+1) + dfs(grid,m,n,i,j+1,steps,s+1);
        grid[i][j] = 0;
        return paths;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int steps = 0;
        int x = 0 , y = 0;
        
        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                if(grid[i][j] != -1) steps++;
            }
        }
        
        return dfs(grid,m,n,x,y,steps,1);
    }
};