class Solution {
public:
    void dfs(int& node, unordered_map<int,vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for(auto& it : adj[node]) {
            if(!visited[it]) {
                dfs(it, adj, visited);
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n);
        int edges = 0;
        
        for(vector<int>& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
            edges++;
        }
        
        if(edges < n-1) return -1;
        
        int connectedComponents = 0;
        
        for(int i = 0 ; i<n ; i++) {
            if(!visited[i]) {
                connectedComponents++;
                dfs(i, adj, visited);
            }
        }
        
        int redundant = edges - ((n - 1) - (connectedComponents - 1));
        
        if(redundant >= connectedComponents - 1) return connectedComponents - 1;
        
        return -1;
    }
};