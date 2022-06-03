class NumMatrix {
private:
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(vector<int> val : mat) {  
            for(int i = 1 ; i<n ; i++) {
                val[i] += val[i-1];
            }
            this->matrix.push_back(val);
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int count = 0;
        
        for(int i = row1 ; i<=row2 ; i++) {
            count -= (col1 > 0) ? this->matrix[i][col1-1] : 0;
            count +=this->matrix[i][col2];   
        }
        
        return count;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */