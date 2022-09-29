class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int absDiff = INT_MAX;
        int ans = INT_MIN;
        
        for(int& num : nums) {
            int absValue = abs(num - 0);
            
            if(absValue == absDiff) {
                ans = max(ans,num);
            } else if(absValue < absDiff) {
                ans = num;
                absDiff = absValue;
            }
        }
            
        return ans;
    }
};