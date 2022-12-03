class Solution {
public:
    static bool compareInterval(pair<int,int> i1, pair<int,int> i2) {
        return (i1.first < i2.first);
    }
    
    string frequencySort(string s) {
        vector<pair<int, int> > count(128);
        
        for(int i = 0 ; i < 128 ; i++) {
            count[i] = make_pair(0,i);
        }
        
        for(char c : s) {
            count[(int)c].first++;
        }
        
        sort(count.begin() , count.end() , compareInterval);
        
        string ans = "";
        
        for(int indx = 127 ; indx>=0 ; indx--) {
            if(count[indx].first > 0) {
                while(count[indx].first != 0) {
                    ans += (char)(count[indx].second);
                    count[indx].first--;
                }   
            }
        }
        return ans;
    }
};