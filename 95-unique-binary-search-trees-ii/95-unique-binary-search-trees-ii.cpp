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
    vector<TreeNode*> generateTrees(int n, int m = 1) {
        if(n < m) {
            return { NULL };
        }
        
        vector<TreeNode*> ans;
        
        for(int i = m ; i<=n ; i++) {
            vector<TreeNode*> treesLeft = generateTrees(i - 1, m);    
            vector<TreeNode*> treesRight = generateTrees(n, i + 1);
            
            for(TreeNode* treeLeft : treesLeft) {
                for(TreeNode* treeRight : treesRight) {
                    ans.push_back(new TreeNode(i, treeLeft, treeRight));
                }
            }
            
        }
        
        return ans;
    }
};