class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // For Top View
        int ans = n * m;
        
        // For Front Side
        for(int i = 0 ; i<n ; i++) {
            int maxi = 0;
            for(int j = 0 ; j<m ; j++) {
                if(grid[i][j] == 0) ans--;
                maxi = max(maxi,grid[i][j]);
            }
            ans += maxi;            
        }
        
        // For Back Side
        for(int i = 0 ; i<m ; i++) {
            int maxi = 0;
            for(int j = 0 ; j<n ; j++) {
                maxi = max(maxi,grid[j][i]);
            }
            ans += maxi;
        }
    
        return ans;
    }
};