class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1) return {};
        
        map<int,int> mp;
        
        for(int& change : changed) {
            mp[change]++;
        }
        
        for(auto& it : mp) {
            if(it.first == 0) {
                if(it.second & 1) return {};
                mp[it.first] = it.second / 2;
                continue;
            }
            
            int num = it.first * 2;
            if(mp.find(num) != mp.end()) {
                if(it.second > 0) mp[num] -= it.second;      
            }
        }
        
        vector<int> ans;
        
        for(auto& it : mp) {
            if(it.second > 0) {
                for(int i = 0 ; i<it.second ; i++) {
                    ans.push_back(it.first);
                }
            }
        }
        
        if(ans.size() == changed.size() / 2) return ans;
        
        return {};
    }
};