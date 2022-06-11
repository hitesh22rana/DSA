class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;

        for(int num : nums) target += num;

        if (target == 0) return nums.size();

        unordered_map<int, int> map;
        
        map[0] = -1;
        
        int sum = 0;
        int res = INT_MIN;
        int n = nums.size();

        for (int i = 0 ; i<n ; i++) {
            sum += nums[i];
            
            if (map.find(sum - target) != map.end()) {
                res = max(res, i - map[sum - target]);
            }

            map[sum] = i;
        }

        return res == INT_MIN ? -1 : n - res;
    }
};