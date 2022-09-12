class Solution {
public:
    bool isPresent(int val, unordered_map<int,vector<int>>& graph, map<int,bool>& visited, int destination) {       
        if(val == destination) return true;

        visited[val] = true;
                
        for(int edge : graph[val]) {
            if(!visited[edge]) {
                bool valid = isPresent(edge,graph,visited,destination);
                if(valid) return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;

        unordered_map<int,vector<int>> graph;
        map<int, bool> visited;
        
        for(vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int>& values = graph[source];
        
        for(int val : values) {
            if(!visited[val]) {
                if(isPresent(val,graph,visited,destination)) return true;            
            }
        }
        
        return false;
    }
};