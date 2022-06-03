class NumMatrix {
private:
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = m > 0 ? mat[0].size() : 0;
        
        this->matrix = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                this->matrix[i][j] = mat[i-1][j-1] + 
                             this->matrix[i-1][j] + this->matrix[i][j-1] - this->matrix[i-1][j-1] ;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->matrix[row2+1][col2+1] - this->matrix[row2+1][col1] - this->matrix[row1][col2+1] + this->matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */