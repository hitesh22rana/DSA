class NumArray {
private:
    vector<int> values;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->values = vector<int>(n,0);
        this->values[0] = nums[0];
        for(int i = 1 ; i<n ; i++) {
            this->values[i] = nums[i]+values[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return left > 0 ? this->values[right] - this->values[left-1] :  this->values[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */