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
    void dfs(TreeNode* root , int k , unordered_map<int,int>& mp , bool& flag) {
        if(root == NULL || flag == true) return;
        dfs(root->left,k,mp,flag);
        if(mp[k-root->val] > 0) flag = true;
        mp[root->val]++;
        dfs(root->right,k,mp,flag);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return false;
        unordered_map<int,int> mp;
        bool flag = false;
        dfs(root,k,mp,flag);
        return flag;
    }
};