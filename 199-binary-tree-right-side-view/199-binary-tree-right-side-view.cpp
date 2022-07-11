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
    void dfs(TreeNode* root, vector<int>& ans, int currDepth) {
        if(root == NULL){
            return;
        }
        
        if(currDepth == ans.size()){
            ans.push_back(root->val);
        }
        
        dfs(root->right, ans, currDepth + 1);
        dfs(root->left, ans, currDepth + 1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        dfs(root,ans,0);
        return ans;
    }
};