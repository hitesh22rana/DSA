class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        maze[entrance[0]][entrance[1]] = '+';
        queue<pair<pair<int,int>, int>> pq;
        pq.push({{entrance[0], entrance[1]}, 0});
        
        while(!pq.empty()) {
            int x = pq.front().first.first;
            int y = pq.front().first.second;
                        
            int level = pq.front().second;
            
            pq.pop();
            
            for(int i = 0 ; i<4 ; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    if(maze[newX][newY] == '+') {
                        continue;
                    }
                    
                    if(newX == 0 || newY == 0 || newX == n-1 || newY == m-1) return level + 1;
                    
                    if(newX >= 0 && newY >= 0 && newX < n && newY < m) {
                        pq.push({{newX, newY}, level + 1});
                        maze[newX][newY] = '+';
                    }
                }
            }
        }
        
        return -1;
        
    }
};