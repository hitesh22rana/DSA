class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int pointG = 0;
        int pointS = 0;
        
        while(pointG < g.size() && pointS < s.size()) {
            if(g[pointG] <= s[pointS]) {
                pointG++;
                pointS++;
            } else {
                pointS++;
            }
        }
        
        return pointG;
    }
};