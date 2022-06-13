class Solution {
private:
    int maxiCount(string s , char num) {
        int count = 0;
        int maxi = 0;
        int n = s.size();  
        
        for(char c : s) {
            if(c != num) {
                maxi = max(count,maxi);
                count = 0;
            } else {
                count++;
            }
        }
        return max(maxi,count);
    }
public:
    bool checkZeroOnes(string s) {
        int zeroMaxi = maxiCount(s,'0');
        int oneMaxi = maxiCount(s,'1');
        return oneMaxi > zeroMaxi;
    }
};