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
    void dfs(TreeNode* root, vector<int> path, int& count) {
        if(root == NULL) {
            return;
        }
        
        if(!root->left && !root->right) {
            path[root->val]++;

            int oddCount = 0;
            
            for(int& val : path) {
                if(val & 1) oddCount++;
            }

            if(oddCount <= 1) count++; 
            
            return;
        }
        
        path[root->val]++;
        dfs(root->left,path,count);
        dfs(root->right,path,count);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> path(10);
        dfs(root,path,count);            
        return count;
    }
};