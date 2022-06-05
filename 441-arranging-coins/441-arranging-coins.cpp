class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 3) {
            return n == 3 ? 2 : 1;
        }
        
        int start = 2;
        int end = n>>1;
        
        while(start <= end) {
            long long int mid = start + ((end-start)>>1);
            long long int val = mid * (mid+1)>>1;
            
            if(val == n) return mid;
            
            else if(val < n) start = mid+1;
            
            else end = mid-1;
            
        }
        
        return end;
    }
};