//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:     
    void dfs(int src, int target, vector<int> graph[], vector<bool> vis, int& ans) {
        if(vis[src]) return;

        if(src == target) {
            ans++;
            return;
        }

        vis[src] = true;

        for(int& child : graph[src]) {
            dfs(child, target, graph, vis, ans);
        }

        vis[src] = false;
    }
    
public:
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<bool> vis(V, false);
        int ans = 0;
        dfs(source, destination, adj, vis, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends