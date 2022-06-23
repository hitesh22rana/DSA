class Solution {
private:
    vector<vector<int>> makeGraph(int numCourses, vector<vector<int>>& list, vector<int>& indegree) {
        vector<vector<int>> graph(numCourses);
        
        for(int i = 0 ; i<list.size() ; i++) {
            graph[list[i][1]].push_back(list[i][0]);
            indegree[list[i][0]]++;
        }
         
        return graph;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {            
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites, indegree);

        queue<int> q;
        for(int i = 0 ; i<numCourses ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        vector<int> ans;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int val : graph[node]) {
                indegree[val]--;
                if(indegree[val] == 0) {
                    q.push(val);
                }
            }
            
            count++;
            ans.push_back(node);
            
        }
        
        if(numCourses != count) return {};
        
        return ans;        
    }
};