class Solution {
private:
    bool checkForCycle(int src, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsVisited, vector<vector<int>>& adjList) {
    visited[src] = true;
    dfsVisited[src] = true;
    
    for(auto neighbour : adjList[src]) {
        if(!visited[neighbour]) {
            bool cycleFound = checkForCycle(neighbour,visited,dfsVisited,adjList);
            if(cycleFound) return true;
        }
        
        else if(dfsVisited[neighbour]) return true;
    }
    dfsVisited[src] = false;
    return false;
}
    
    bool isCycle(int n, vector<vector<int>>& graph) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        
        for(int i = 0 ; i<n ; i++) {
            if(!visited[i]) {
                bool cycleFound = checkForCycle(i,visited,dfsVisited,graph);
                if(cycleFound) return true;
            }
        }
        return false;
    }    
    
    vector<vector<int>> makeGraph(int numCourses, vector<vector<int>>& list) {
        vector<vector<int>> graph(numCourses);
        
        for(vector<int> edge : list) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        return graph;
    }
    
    void topologicalSort(int edge, vector<bool>& visited, vector<vector<int>>& graph , vector<int>& ans) {         
        visited[edge] = true;
        
        for(int children : graph[edge]) {
            if(!visited[children]) {
                topologicalSort(children,visited,graph,ans);   
            }
        }
        ans.push_back(edge);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<bool> visited(numCourses , false);
        
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        
        if(isCycle(numCourses, graph)) return {};
        
        for(int i = 0 ; i<numCourses ; i++) {
            if(!visited[i]) {
                topologicalSort(i,visited,graph,ans);
            }
        }
        
        return ans;
    }
};