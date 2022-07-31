class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int s = 0, e = grades.size(), ans = 0;
        
        while(s <= e) {
            long long int mid = s + (e-s)/2;
            long long int sum = (long long int)(mid * (mid+1)) / 2;
            
            if(sum <= grades.size()) {
                ans = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }
            
        }
        
        return ans;
    }
};