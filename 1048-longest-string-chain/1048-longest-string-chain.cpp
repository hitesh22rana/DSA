class Solution {
private:
    static bool compareInterval(string s1 , string s2) {
        return s1.size() < s2.size();
    }

public:

    int longestStrChain(vector<string>& words) {

        if(words.size() == 0) return 0;
        int res = 0;
        sort(words.begin() , words.end() , compareInterval);
        unordered_map<string, int> map; 

        for(string w : words) {                             
            map[w] = 1;                                  
            for(int i = 0; i<w.size(); i++) {               
                string sb = w;
                string next = sb.erase(i, 1);
                if(map.find(next) != map.end() && map[next]+1 > map[w])
                    map[w] = map[next]+1;           
            }
            res = max(res, map[w]); 
        }
	    return res;
    }
};