//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool DFS(int src, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis, vector<bool>& check) {
        if(vis[src] && pathVis[src]) return true;
        
        if(vis[src]) return false;
        
        vis[src] = true;
        pathVis[src] = true;
        check[src] = false;
        
        for(int node : adj[src]) {
            if(DFS(node, adj, vis, pathVis, check)) return true;
        }
        
        pathVis[src] = false;
        check[src] = true;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        vector<bool> check(V, false);
        vector<int> ans;
        
        for(int i = 0 ; i<V ; i++) {
            if(!vis[i]) {
                DFS(i, adj, vis, pathVis, check);
            }
        }
        
        for(int i = 0 ; i<V ; i++) {
            if(check[i]) ans.push_back(i);
        }
        
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends