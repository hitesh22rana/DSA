class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> values(51);

        for(vector<int>& range : ranges) {
            for(int i = range[0] ; i<=range[1] ; i++) {
                values[i] = true;
            }
        }
        
        for(int i = left ; i<=right ; i++) {
            if(!values[i]) return false;
        }
        
        return true;
    }
};