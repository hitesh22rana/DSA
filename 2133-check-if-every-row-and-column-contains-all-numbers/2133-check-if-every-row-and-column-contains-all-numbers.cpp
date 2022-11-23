class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0 ; i<n ; i++) {
            set<int> strow, stcol;
            for(int j = 0 ; j<n ; j++) {
                strow.insert(matrix[i][j]);
            }
            if(strow.size() != n) return false;
            
            for(int j = 0 ; j<n ; j++) {
                stcol.insert(matrix[j][i]);
            }
            if(stcol.size() != n) return false;
            
        }
        
        return true;
    }
};