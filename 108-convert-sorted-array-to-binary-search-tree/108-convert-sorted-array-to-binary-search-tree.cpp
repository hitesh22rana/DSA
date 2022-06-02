/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* BSTConversion(vector<int>& nums , int start , int end) {
        if(start >= end) return NULL;
        int midIndx = start + ((end-start)>>1);
        TreeNode* root = new TreeNode(nums[midIndx]);
        root->left = BSTConversion(nums , start , midIndx);
        root->right = BSTConversion(nums , midIndx+1 , end);
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BSTConversion(nums,0,nums.size());
    }
};