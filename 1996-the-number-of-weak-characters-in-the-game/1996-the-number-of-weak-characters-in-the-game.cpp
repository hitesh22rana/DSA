class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        unordered_map<int,vector<int>> mp;
        int minAttack = INT_MAX;
        int maxAttack = 0;
        
        for(vector<int>& property : properties) {
            minAttack = min(minAttack,property[0]);
            maxAttack = max(maxAttack,property[0]);
            mp[property[0]].push_back(property[1]);
        }
        
        int count = 0;
        int maxDefence = -1;
        
        for(int i = maxAttack ; i>=minAttack ; i--) {
            if(mp.find(i) == mp.end()) continue;
            
            vector<int>& arr = mp[i];    
            int maxi = arr[0];
            
            for(int& val : arr) {
                maxi = max(val,maxi);
                if(val < maxDefence) count++;
            }
            
            maxDefence = max(maxi,maxDefence);
        }        
        
        return count;
    }
};