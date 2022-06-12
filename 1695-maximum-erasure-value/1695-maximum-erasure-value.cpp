class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int start = 0 , end = 0;
        long long int maxi = 0 , sum = 0;
        
        unordered_set<int> st;
        
        while(start < n && end < n) {
            if(!(st.find(nums[end]) != st.end())) {
                sum += nums[end];
                maxi = max(sum,maxi);
                st.insert(nums[end++]);
            } else {
                sum -= nums[start];
                st.erase(nums[start++]);
            }
        }
        
        return maxi;
    }
};