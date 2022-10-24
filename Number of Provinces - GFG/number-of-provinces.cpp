//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(vector<int> adj[], int node, vector<bool>& visited) {
        visited[node] = true;
        
        for(auto& it : adj[node]) {
            if(!visited[it]) {
                dfs(adj, it, visited);
            }
        }
        
    }
    
  public:
    int numProvinces(vector<vector<int>> adjMat, int V) {
        vector<int> adj[V];
        
        for(int i = 0 ; i<V ; i++) {
            for(int j = 0 ; j<V ; j++) {
                if(adjMat[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(V);
        int count = 0;
        
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends