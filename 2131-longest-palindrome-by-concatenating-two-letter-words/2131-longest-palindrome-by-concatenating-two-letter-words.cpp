class Solution {
public:
    int longestPalindrome(vector<string>& words) {       
        unordered_map<string,int> mp;
        int ans = 0;

        for(string& word : words) {
            mp[word]++;
        }
        
        bool isMiddle = false;
        
        for(auto& it : mp) {
            string rev = it.first;
            reverse(rev.begin(), rev.end());
            
            if(it.first == rev) {
                if(it.second == 1) {
                    if(!isMiddle) {
                        ans += 2;
                        isMiddle = true;
                    }
                } else {
                    if(it.second & 1) {
                        ans += (it.second - 1) * 2;
                        if(!isMiddle) ans += 2;
                        isMiddle = true;
                    } else {
                        ans += it.second * 2;                    
                    }
                }
            }
            else if(mp.find(rev) != mp.end()) {
                ans += min(it.second, mp[rev]) * 2;
            }
        }
        
        return ans;
    }
};