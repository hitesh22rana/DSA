//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution  {
public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>& grid) {
	    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
	    vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
	    queue<pair<pair<int,int>, int>> q;
	    
	    for(int i = 0 ; i<grid.size() ; i++) {
	        for(int j = 0 ; j<grid[0].size() ; j++) {
	            if(grid[i][j] == 1) {
	                q.push({{i, j}, 0});
	                visited[i][j] = true;
	            }
	        }
	    }
	    
	    int N = grid.size();
	    int M = grid[0].size();
	    
	    vector<int> dx = {-1, 0, 1, 0};
	    vector<int> dy = {0, 1, 0, -1};
	    
	    while(!q.empty()) {
    	   int x = q.front().first.first;
    	   int y = q.front().first.second;
    	   int level = q.front().second;
    	   q.pop();
    	   
    	   ans[x][y] = level;
    	   
    	   for(int i = 0 ; i<4 ; i++) {
    	       int nrow = dx[i] + x;
    	       int ncol = dy[i] + y;
    	       
    	       if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && visited[nrow][ncol] == false) {
    	           visited[nrow][ncol] = true;
    	           q.push({{nrow, ncol}, level + 1});
    	       }
    	       
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends