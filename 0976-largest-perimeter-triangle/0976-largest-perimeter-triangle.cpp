class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int perimeter = 0;
        
        for(int i = 0 ; i<n-2 ; i++) {
            
            int s1 = nums[n-i-1];
            int s2 = nums[n-i-2];
            int s3 = nums[n-i-3];

            double s = (double)(s1 + s2 + s3) / (double)2;

            double area = s*(s - s1)*(s - s2)*(s - s3);
            
            if(area > 0) {
                perimeter = max(perimeter, s1 + s2 + s3);
            }
        }
        
        return perimeter;
    }
};