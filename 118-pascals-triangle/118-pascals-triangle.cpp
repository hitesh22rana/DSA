class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        if(numRows == 1) return triangle;
        
        triangle.push_back({1,1});
        if(numRows == 2) return triangle;
        
        for(int i = 2 ; i<numRows ; i++) {
            vector<int> temp;
            temp.push_back(1);
            
            for(int j = 0 ; j<i-1 ; j++) {
                temp.push_back(triangle[i-1][j] + triangle[i-1][j+1]);    
            }
            
            temp.push_back(1);
            triangle.push_back(temp);
        }
        
        return triangle;
    }
};