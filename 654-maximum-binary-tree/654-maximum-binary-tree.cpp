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
public:
    int maxi(vector<int>& nums, int l, int r) {
        int maxIndex = l;
        
        for(int i = l ; i<r ; i++) {
            if(nums[maxIndex] < nums[i]) {
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
    
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if(l >= r) return NULL;
        
        int maxIndex = maxi(nums,l,r);
        
        TreeNode* node = new TreeNode(nums[maxIndex]);
        
        node->left = construct(nums,l,maxIndex);
        node->right = construct(nums,maxIndex+1,r);
        
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums,0,nums.size());
    }
};