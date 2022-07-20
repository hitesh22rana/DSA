class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26);
        
        for(int i = 0 ; i<s.size() ; i++) {
            mp[s[i]-'a'].push_back(i);
        }
        
        int count = 0;
        
        for(string &word : words) {
            int indx = -1;
            bool isFound = true;
            
            for(char c : word) {
				auto it = upper_bound (mp[c - 'a'].begin(), mp[c - 'a'].end(), indx);
				if(it == mp[c - 'a'].end()) {
                    isFound = false;
                    break;
                }
				else indx = *it;
			}

			if(isFound) count++;
            
        }
        
        return count;
    }
};