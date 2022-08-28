class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> counts(garbage.size());
        
        counts[0] = 0;
        for(int i = 1 ; i<garbage.size() ; i++) {
            counts[i] += travel[i-1] + counts[i-1];
        }
        
        unordered_map<char,vector<int>> mp;
        
        for(int i = 0 ; i<garbage.size() ; i++) {
            string s = garbage[i];
            for(char& c : s) {
                if(c == 'M') {
                    if(!mp['M'].empty() && mp['M'].back() != i) {
                        mp['M'].push_back(i);
                    } else if(mp['M'].empty()) {
                        mp['M'].push_back(i);                        
                    }
                }
                else if(c == 'P') {
                    if(!mp['P'].empty() && mp['P'].back() != i) {
                        mp['P'].push_back(i);
                    } else if(mp['P'].empty()) {
                        mp['P'].push_back(i);                        
                    }
                } else {
                   if(!mp['G'].empty() && mp['G'].back() != i) {
                        mp['G'].push_back(i);
                    } else if(mp['G'].empty()) {
                        mp['G'].push_back(i);                        
                    }
                }
                    
            }
        }
        
        int count = 0;
        
        for(auto it : mp) {
            vector<int>& stops = it.second;
            
            for(int i = 0 ; i<stops.size() ; i++) {
                
                int valCount = 0;

                for(char& c : garbage[stops[i]]) {
                    if(c == it.first) valCount++;
                }

                if(stops[i] == 0) {
                    count += valCount;
                } else {
                    count += counts[stops[i]] + valCount;                

                    if(i-1 >= 0) {
                        count -= counts[stops[i-1]];                   
                    }
                }
                
            }   
        }
        
        return count;
    }
};