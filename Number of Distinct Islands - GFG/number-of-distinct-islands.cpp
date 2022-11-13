//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void islandsCoOrdinates(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& directions) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) return;
        directions.push_back({i,j});
        visited[i][j] = true;
        
        islandsCoOrdinates(i+1,j,grid,visited,directions);
        islandsCoOrdinates(i,j+1,grid,visited,directions);
        islandsCoOrdinates(i-1,j,grid,visited,directions);
        islandsCoOrdinates(i,j-1,grid,visited,directions);
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        set<vector<vector<int>>> ans;
        
        for(int i = 0 ; i<grid.size() ; i++) {
            for(int j = 0 ; j<grid[0].size() ; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<vector<int>> directions;
                    islandsCoOrdinates(i,j,grid,visited, directions);
                    if(directions.size()) {
                        vector<int> base = directions[0];
                        
                        for(int i = 0 ; i<directions.size() ; i++) {
                            vector<int> val = directions[i];
                            directions[i] = {val[0] - base[0], val[1] - base[1]};
                        }
                        
                        ans.insert(directions);
                    }
                }
            }
        }
        
        return ans.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends