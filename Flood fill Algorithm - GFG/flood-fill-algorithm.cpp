//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void fill(int i, int j, int newColor, int startingColor, vector<vector<int>>& image, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != startingColor || visited[i][j] == true) return;
        
        visited[i][j] = true;
        image[i][j] = newColor;
        
        for(int k = 0 ; k<4 ; k++) {
            fill(dx[k] + i, dy[k] + j, newColor, startingColor, image, visited);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        
        fill(sr, sc, newColor, image[sr][sc], image, visited);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends