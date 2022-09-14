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
    int sumOfBst(TreeNode* root) {
        if(root == NULL) return 0;
        return root->val + sumOfBst(root->left) + sumOfBst(root->right);
    }
    
    void dfs(TreeNode* root, int sum, int& currentSum) {
        if(root == NULL) return;
        
        dfs(root->left, sum, currentSum);
        int val = root->val;
        root->val = sum - currentSum;
        currentSum += val;
        dfs(root->right, sum, currentSum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = sumOfBst(root);
        int currentSum = 0;
        dfs(root,sum,currentSum);
        return root;
    }
};