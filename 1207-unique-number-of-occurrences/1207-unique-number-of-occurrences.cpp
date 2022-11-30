class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(int& val : arr) {
            mp[val]++;
        }
        
        unordered_set<int> freqs;
        for(auto it : mp) {
            int freq = it.second;           
            
            if(freqs.find(freq) != freqs.end()) return false;
            freqs.insert(freq);
        }
        
        return true;
    }
};