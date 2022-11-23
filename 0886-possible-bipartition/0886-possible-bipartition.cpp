class Solution {
private:
    bool isBipartite(int src, int color, unordered_map<int, vector<int>>& adjList, vector<int>& vis) {
        queue<int> q;
        q.push(src);
        
        vis[src] = color;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int child : adjList[node]) {
                if(vis[child] == -1) {
                    if(vis[node] == 1) {
                        vis[child] = 0;
                    } else if(vis[node] == 0) {
                        vis[child] = 1;
                    }
                    q.push(child);
                } else if(vis[node] == vis[child]) return false;
            }
            
        }
        
        return true;
    }
    
public:    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList;
        
        for(vector<int>& dislike : dislikes) {
            adjList[dislike[0]].push_back(dislike[1]);
            adjList[dislike[1]].push_back(dislike[0]);
        }
        
        vector<int> vis(n + 1 , -1);
        
        for(int i = 0 ; i<n ; i++) {
            if(vis[i] == -1) {
                if(!isBipartite(i, 0, adjList, vis)) return false;
            }
        }
        
        return true;
    }
};