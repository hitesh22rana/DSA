class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0 ; i<matrix.size() ; i++) {
            int index = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if(index < matrix[0].size() && matrix[i][index] == target) return true;
        }
        return false;
    }
};