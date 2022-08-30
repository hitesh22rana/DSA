class Solution {
public:
     void transpose(vector<vector<int>>& matrix , int n) {        
        for(int i = 0 ; i<n ; i++) {
            for(int j = i+1 ; j<n ; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }    
        }
    }
    
    void columnRotate(vector<vector<int>>& matrix , int n) {
        int s = 0;
        int e = n-1;
        
        while(s < e) {
            for(int i = 0 ; i<n ; i++) {
                swap(matrix[i][s],matrix[i][e]);
            }
            s++;
            e--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix , matrix.size());
        columnRotate(matrix , matrix.size());
    }
};