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
    void dfs(TreeNode* root, int targetSum, int sum, vector<vector<int>>& ans, vector<int> values) {
        if(root == NULL) {
            return;
        }
        
        sum += root->val;
        values.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            
            if(targetSum == sum) {
                ans.push_back(values);
            }
            return;
        }
        
        dfs(root->left,targetSum,sum, ans, values);
        dfs(root->right,targetSum,sum,ans,values);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        dfs(root,targetSum,0,ans,{});
        return ans;
    }
};