class Solution {
private:
    int maxDiff(vector<int>& values) {
        int maxi = values[0];
        int n = values.size();
        
        for(int i = 1 ; i<n ; i++) {
            maxi = max(maxi,values[i]-values[i-1]);
        }
        
        return maxi;
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int horizontalMax = maxDiff(horizontalCuts);
        int verticalMax = maxDiff(verticalCuts);
        const int MOD = 1e9+7;
        
        long long int ans = ((long long int)max(horizontalMax,h-horizontalCuts[horizontalCuts.size()-1]) * (long long int)max(verticalMax,w-verticalCuts[verticalCuts.size()-1])) % MOD;
        
        return ans;
    }
};