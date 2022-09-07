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
    void dfs(TreeNode* root, string &ans) {
        if(root == NULL) {
            return;    
        }
        
        ans.push_back('(');
        ans += to_string(root->val);
        dfs(root->left,ans);
        
        if(!root->left && root->right) {
            ans.push_back('(');
            ans.push_back(')');
        }
        
        dfs(root->right,ans);
        ans.push_back(')');
    }
    
    string tree2str(TreeNode* root) {
        string ans = "";
        dfs(root,ans);
        ans.pop_back();
        return ans.substr(1);
    }
};