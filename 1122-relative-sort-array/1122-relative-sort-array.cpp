class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> mp(1001,0);
        
        for(int &val : arr1) {
            mp[val]++;
        }
        
        int start = 0;
        
        for(int &val : arr2) {
            int times = mp[val];
            
            for(int i = 0 ; i<times ; i++) {
                arr1[start++] = val;
                mp[val]--;
            }
            
        } 
        
        for(int i = 0 ; i<1001 ; i++) {
            if(mp[i] > 0) {
                int times = mp[i];
                
                for(int j = 0 ; j<times ; j++) {
                    arr1[start++] = i;
                    mp[i]--;
                }
            }
        }
        
        return arr1;
    }
};