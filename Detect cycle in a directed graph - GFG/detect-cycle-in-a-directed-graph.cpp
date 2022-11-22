//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool DFS(int src, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis) {
        if(vis[src] && pathVis[src]) return true;
        
        if(vis[src]) return false;
        
        vis[src] = true;
        pathVis[src] = true;
        
        for(int node : adj[src]) {
            if(DFS(node, adj, vis, pathVis)) return true;
        }
        
        pathVis[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        
        for(int i = 0 ; i<V ; i++) {
            if(!vis[i]) {
                if(DFS(i, adj, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends