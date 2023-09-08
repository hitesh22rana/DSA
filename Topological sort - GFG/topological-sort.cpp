//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int src, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
        vis[src] = true;
        
        for(int& node : adj[src]) {
            if(!vis[node])
                dfs(node, adj, vis, st);
        }
        
        st.push(src);
    }

	vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int> st;
        vector<bool> vis(V);
        
        for(int i = 0 ; i<V ; i++) {
            if(!vis[i])
                dfs(0, adj, vis, st);
        }
        
        vector<int> sortedValues;
        while(!st.empty()) {
            sortedValues.push_back(st.top());
            st.pop();
        }
        
        return sortedValues;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends