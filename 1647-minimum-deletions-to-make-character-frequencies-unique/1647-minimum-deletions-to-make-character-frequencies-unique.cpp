class Solution {
private:
    static bool compare(pair<char,int> p1 , pair<char,int> p2) {
        return p1.second > p2.second;
    }
    
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        
        for(char c : s) count[c-'a']++;
        
        vector<pair<char,int> > freq;
        
        for(int i = 0 ; i<26 ; i++) {
            if(count[i] > 0) {
                freq.push_back(make_pair(i+'a',count[i]));   
            }
        }
        
        sort(freq.begin(),freq.end(),compare);
        
        int cnt = 0;
        
        int n = freq.size();
        
        for(int i = 0 ; i<n-1 ; i++) {
           
            if(freq[i+1].second > freq[i].second) {
                cnt += (freq[i+1].second - freq[i].second);
                freq[i+1].second = freq[i].second;
            }

            
            if(freq[i].second == freq[i+1].second) {
                if(freq[i+1].second > 0) {
                    freq[i+1].second--;
                    cnt++;    
                }
            }
            
        }
        
        return cnt;
    }
};