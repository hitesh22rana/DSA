class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int prefix[arr.size()];
        prefix[0] = arr[0];
        
        for(int i = 1 ; i<arr.size() ; i++) {
            prefix[i] = prefix[i-1] ^ arr[i];
        }
        
        for(vector<int>& query : queries) {
            int left = query[0];
            int right = query[1];
                        
            if(left == 0) ans.push_back(prefix[right]);
             
            else {
                int val = prefix[right] ^ prefix[left - 1];
                ans.push_back(val);
            }            
        }
        
        return ans;
    }
};