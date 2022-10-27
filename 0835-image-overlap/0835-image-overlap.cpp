class Solution {
public:
    int maxOverlaps(int& xShift, int& yShift, vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int overlaps = 0;
        int n = img1.size();
        
        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(0 <= j + xShift && j + xShift < n && 0 <= i + yShift && i + yShift < n && img1[i + yShift][j + xShift] == 1 && img2[i][j] == 1) {
                    overlaps++;
                }
            }
        }
        
        return overlaps;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi = 0;
        int n = img1.size();
        
        for(int i = -n ; i<n ; i++) {
            for(int j = -n ; j<n ; j++) {
                maxi = max(maxi, maxOverlaps(i, j, img1, img2));
            }
        }
        
        return maxi;
    }
};