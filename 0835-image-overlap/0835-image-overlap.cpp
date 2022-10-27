class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> non_zero1;
        vector<pair<int,int>> non_zero2;
        
        for(int i = 0 ; i<img1.size() ; i++) {
            for(int j = 0 ; j<img1[0].size() ; j++) {
                if(img1[i][j] == 1) {
                    non_zero1.push_back({i,j});
                }
                
                if(img2[i][j] == 1) {
                    non_zero2.push_back({i,j});
                }
            }
        }
        
        int ans = 0;
        map<pair<int,int>, int> mp;
        
        for(auto& it1 : non_zero1) {
            for(auto& it2 : non_zero2) {
                mp[{it2.first - it1.first, it2.second - it1.second}]++;
                ans = max(ans, mp[{it2.first - it1.first, it2.second - it1.second}]);
            }
        }
        
        return ans;
    }
};