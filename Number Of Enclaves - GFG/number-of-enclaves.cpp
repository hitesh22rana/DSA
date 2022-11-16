//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& cnt) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || vis[row][col] || grid[row][col] == 0) return;
        cnt++;
        vis[row][col] = true;

        for(int i = 0 ; i<4 ; i++) {
            dfs(row + dx[i], col + dy[i], grid, vis, cnt);
        }

    }
    
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int totalOnes = 0;
        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if(grid[i][j] == 1) totalOnes++;
            }
        }
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int ans = 0;
        for(int i = 0 ; i<n ; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis, ans);
                // cout<<i<<", "<<0<<" : "<<ans<<"\n";
            }
            
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis, ans);
                // cout<<i<<", "<<m-1<<" : "<<ans<<"\n";
            }
        }
        
        for(int i = 0 ; i<m ; i++) {
            if(!vis[0][i] && grid[0][i] == 1) {
                dfs(0, i, grid, vis, ans);
                // cout<<0<<", "<<i<<" : "<<ans<<"\n";
            }
            
            if(!vis[n-1][i] && grid[n-1][i] == 1) {
                dfs(n-1, i, grid, vis, ans);
                // cout<<n-1<<", "<<i<<" : "<<ans<<"\n";
            }
        }
        
        return totalOnes - ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends