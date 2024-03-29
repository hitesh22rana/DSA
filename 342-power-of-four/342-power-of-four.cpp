class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n <= 3) return false;
        double num = (double)log(n)/log(4);
        return pow(4,(int)num) == n;
    }
};