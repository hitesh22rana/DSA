//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution  {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        int ans = 0;
        
        for(int i = 0 ; i<grid.size() ; i++) {
            for(int j = 0 ; j<grid[0].size() ; j++) {
                if(grid[i][j] == 2) {
                    q.push({make_pair(i,j), 0});
                }
            }
        }
         
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                pair<pair<int,int>, int> p = q.front();
                ans = max(ans, p.second);
                pair<int,int> coOrdinates = p.first;
                q.pop();
                
                for(int k = 0 ; k<4 ; k++) {
                    int x = coOrdinates.first + dx[k];
                    int y = coOrdinates.second + dy[k];
                    
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({make_pair(x,y), p.second + 1});
                    }
                    
                }
            }
            
        }
        
        for(int i = 0 ; i<grid.size() ; i++) {
            for(int j = 0 ; j<grid[0].size() ; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends