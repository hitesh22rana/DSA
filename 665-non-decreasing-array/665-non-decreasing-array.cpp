class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i;
        int n = nums.size();
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(nums[i+1] < nums[i]){
                flag++;
                if((i!=0 && nums[i+1] < nums[i-1]) && (i!=n-2 && nums[i] > nums[i+2])){
                    return false;
                }
            }
            if(flag > 1){
                return false;
            }
        }
        return true;
    }
};