class Solution {
public:
    int MOD = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int> mp;
        
        for(int& val : arr) {
            mp[val] = 1;
        }
        
        for(int i = 0 ; i<arr.size() ; i++) {
            long long int count = 0;
            
            for(int j = 0 ; j<i ; j++) {
                if(arr[i] % arr[j] == 0) {
                    auto it = mp.find(arr[i]/arr[j]);
                    
                    if(it != mp.end()) {
                        count += (long long int)it->second * (long long int)mp[arr[j]] ;
                    }
                    
                }
            }
            
            mp[arr[i]] += count;
        }
        
        long long int ans = 0;
        
        for(auto& num : mp) {
            ans += num.second;
        }
        
        return ans % MOD;
    }
};