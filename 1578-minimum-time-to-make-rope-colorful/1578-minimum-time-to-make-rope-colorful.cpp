class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        
        for(int i = 0 ; i<colors.size() ; i++) {
            char c = colors[i];
                        
            int count = 0;
            int j = i;
            
            while(j < colors.size() && colors[j] == c) {
                count++;
                j++;
            }
                            
            if(count == 1) continue;
            
            int maxi = neededTime[i];
            int index = i;
            
            for(int k = i ; k<j ; k++) {
                if(neededTime[k] > maxi) {
                    maxi = neededTime[k];
                    index = k;
                }
            }
            
            for(int k = i ; k<j ; k++) {
                if(index == k) continue;
                ans += neededTime[k];
            }
            
            i = j - 1;
        }
        
        return ans;
    }
};