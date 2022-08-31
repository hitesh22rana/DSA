class Solution {
public:
    void dfs(int r, int c, set<pair<int,int>>& visit, int prevHeight, vector<vector<int>>& heights) {
        pair<int,int> p = {r,c};
        if(visit.find(p) != visit.end() || r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || heights[r][c] < prevHeight) {
            return;
        }
        
        visit.insert(p);
        
        dfs(r+1, c, visit, heights[r][c], heights);
        dfs(r-1, c, visit, heights[r][c], heights);
        dfs(r, c+1, visit, heights[r][c], heights);
        dfs(r, c-1, visit, heights[r][c], heights);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;
        
        for(int i = 0 ; i<n ; i++) {
            dfs(0,i,pacific,heights[0][i],heights);
            dfs(m-1,i,atlantic,heights[m-1][i],heights);
        }
        
        for(int i = 0 ; i<m ; i++) {
            dfs(i,0,pacific,heights[i][0],heights);
            dfs(i,n-1,atlantic,heights[i][n-1],heights);
        }
        
        vector<vector<int>> ans;
        
        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                pair<int,int> p = {i,j};
                if((pacific.find(p) != pacific.end()) && (atlantic.find(p) != atlantic.end())) {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};