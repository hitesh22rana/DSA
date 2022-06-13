class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        
        for(int num : nums) {
            if(num == 0) {
                maxi = max(count,maxi);
                count = 0;
            } else {
                count++;        
            }
        }
        return max(count,maxi);
    }
};