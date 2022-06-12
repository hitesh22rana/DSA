class Solution {
private:
    void area(vector<vector<int>>& grid , int x , int y , int& ans , int m , int n) {
        if(x < 0 || x >= m || y < 0 || y>=n || grid[x][y] != 1) return;
        
        grid[x][y] = -1;
        ans++;
        
        area(grid,x-1,y,ans,m,n);
        area(grid,x,y-1,ans,m,n);
        area(grid,x+1,y,ans,m,n);
        area(grid,x,y+1,ans,m,n);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxi = 0;

        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(grid[i][j] == 1) {
                    int ans = 0;
                    area(grid,i,j,ans,m,n);
                    maxi = max(ans,maxi);
                }
            }
        }
        return maxi;
    }
};