class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,list<int>> adj;
        set<int> st;
        
        for(int& val : restricted) st.insert(val);
                
        for(int i = 0 ; i<edges.size() ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
               
        queue<int> q;
        vector<bool> seen(n);
        int count = 0;
        
        seen[0] = true;
        q.push(0);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            if(st.find(node) != st.end()) continue;
            
            count++;

            for(auto val : adj[node]) {
                if(!seen[val]) {
                    seen[val] = true;
                    q.push(val);
                }
            }
        }
        return count;
    }
};