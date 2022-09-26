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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;        
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});
        int level = 1;
        
        while(!q.empty()) {
            int n = q.size();
            
            vector<int> val;
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) {
                    q.push(node->left);
                    val.push_back(node->left->val);
                }
                
                if(node->right) {
                    q.push(node->right);
                    val.push_back(node->right->val);
                }
            }    
            
            if(level & 1) {
                reverse(val.begin(),val.end());
            }
            
            if(val.size() > 0) {
                ans.push_back(val);            
            }
            level++;
        }
        
        return ans;
    }
};