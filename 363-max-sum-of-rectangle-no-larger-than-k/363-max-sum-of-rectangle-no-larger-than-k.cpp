class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = INT_MIN;
        
        for(int left = 0 ; left < col ; left++) {
            vector<int> prefixSums(row);
 
            for(int right = left ; right < col ; right++) {
                for(int i = 0 ; i<row ; i++) {
                    prefixSums[i] += matrix[i][right];
                }
                
                set<int> s = {0};
                int r_sum = 0;
                    
                for(int sum : prefixSums) {
                    r_sum += sum;
                    auto it = s.lower_bound(r_sum - k);
                    if(it != end(s)) {
                        res = max(res, r_sum - *it);
                    }
                    s.insert(r_sum);
                }
            }
        }
        
        return res;
    }
};