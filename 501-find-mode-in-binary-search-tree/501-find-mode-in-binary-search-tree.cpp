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
    int maxi = 0, freq = 0, prev = INT_MIN;
    vector<int> ans;

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev == root->val) freq++;
        else freq = 1;
        
        if (freq > maxi) {
            ans.clear();
            maxi = freq;
            ans.push_back(root->val);
        }
        
        else if (freq == maxi) {
            ans.push_back(root->val);
        }
        
        prev = root->val;
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;        
    }
};