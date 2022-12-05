class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        
        int xors = 0;
        
        for(int& val : pref) {
            int num;
            
            if(xors == 0) {
                ans.push_back(val);
                num = val;
            } else {
                num = val ^ xors;
                ans.push_back(num);
            }
            
            xors ^= num;
        }
        
        return ans;
    }
};