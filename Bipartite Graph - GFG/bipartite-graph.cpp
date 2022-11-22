//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool BFS(int src, vector<int> adj[], vector<int>& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int child : adj[node]) {
                if(vis[child] == -1) {
                    if(vis[node] == 0) {
                        vis[child] = 1;
                    } else if(vis[node] == 1) {
                        vis[child] = 0;
                    }
                    q.push(child);
                } else if(vis[node] == vis[child]) {
                     return true;
                }
            }
        }
        
        return false;
    }

	bool isBipartite(int V, vector<int> adj[]){
        vector<int> vis(V , -1);
        
        for(int i = 0 ; i<V ; i++) {
            if(vis[i] == -1) {
                if(BFS(i, adj, vis)) return false;
            }
        }
        
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends