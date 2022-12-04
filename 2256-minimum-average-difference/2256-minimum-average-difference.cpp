class Solution {
private:
    long long int sum(vector<int>& nums) {
        long long int count = 0;
        for(int val : nums) {
            count += val;
        }
        return count;
    }

public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int total = sum(nums);
        long long int sumFromStart = 0;
        
        long long int mini = INT_MAX;
        long long int ans = 0;
        int n = nums.size();
        long long int diff;
        
        for(int i = 1 ; i<n ; i++) {
            sumFromStart += nums[i-1];
            diff = abs((sumFromStart/i) - (total-sumFromStart)/(n-i));
            if(diff < mini) {
                mini = diff;
                ans = i-1;
            }
        }
        diff = abs(total/n);
        
        if(mini>diff) {
            mini = diff;
            ans = n-1;
        }
        return ans;
    }
};