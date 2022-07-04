class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ltr(n,1);
        vector<int> rtl(n,1);
        
        // For LTR 
        for(int i = 1 ; i<n ; i++) {
            if(ratings[i] > ratings[i-1]) ltr[i] = ltr[i-1] + 1;
        }
            
        // For RTL
        for(int i = n-2 ; i>=0 ; i--) {
            if(ratings[i] > ratings[i+1]) rtl[i] = rtl[i+1] + 1;
        }
        
        int sum = 0;
        for (int i = 0 ; i<n ; i++) {
            sum += max(ltr[i],rtl[i]);
        }
        
        return sum;
    }
};