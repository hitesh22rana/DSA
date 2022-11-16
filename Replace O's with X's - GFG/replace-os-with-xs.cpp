//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& mat, vector<vector<bool>>& vis) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || mat[i][j] != 'O') return;
        
        vis[i][j] = true;
        
        for(int k = 0 ; k<4 ; k++) {
            dfs(dx[k] + i, dy[k] + j, n, m, mat, vis);
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0 ; i<m ; i++) {
            if(!vis[0][i] && mat[0][i] == 'O') {
                dfs(0, i, n, m, mat, vis);
            }
            
            if(!vis[n-1][i] && mat[n-1][i] == 'O') {
                dfs(n-1, i, n, m, mat, vis);
            }
        }
        
        for(int i = 0 ; i<n ; i++) {
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, n, m, mat, vis);
            }
            
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m-1, n, m, mat, vis);
            }
        }
        
        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends