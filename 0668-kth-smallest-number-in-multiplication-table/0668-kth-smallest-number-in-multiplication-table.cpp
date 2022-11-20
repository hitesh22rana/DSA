class Solution {
public:
    bool check(int m, int n, int k, int mid) {
        int count = 0;
        
        for(int i = 1 ; i<=n ; i++) {
            count += min(m, mid / i);
        }
        
        return count >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int start = 0;
        int end = m*n;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(check(m, n, k, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};