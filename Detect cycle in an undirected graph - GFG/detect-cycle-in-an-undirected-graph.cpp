//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(int src, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int,int>> q;
        q.push(make_pair(src,-1));
    
        visited[src] = true;
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            
            for(int &node : adj[p.first]) {
                if(!visited[node]) {
                    q.push(make_pair(node, p.first));
                    visited[node] = true;
                } else if(p.second != node) {
                    return true;
                }
            }

        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i]) {
                bool detectCycle = detect(i, adj, visited);
                
                if(detectCycle) return true;
            }
        }
        
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends