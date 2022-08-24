class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        if(n <= 2 || n % 3 != 0) return false;
        
        long long int powerOfThree = 3;
        for(int i = 0 ; i<33 ; i++) {
            if(powerOfThree == n) return true;
            powerOfThree *= 3;
        }
        
        return false;
    }
};