class Solution {
private:
    static bool compare(vector<int>& p1 , vector<int>& p2) {
        return p1[1] < p2[1];
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(), compare);
        int ans = 1;
        int point = points[0][1];
        
        for(int i=1 ; i<n ; i++) {
            if(points[i][0]>point || points[i][1]<point) {
                point = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};