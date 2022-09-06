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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front().first;
                pair<int,int> p = q.front().second;
                q.pop();

                mp[p.first][p.second].insert(node->val);

                if(node->left) {
                    q.push(make_pair(node->left,make_pair(p.first - 1,p.second + 1)));
                }

                if(node->right) {
                    q.push(make_pair(node->right,make_pair(p.first + 1,p.second + 1)));
                }
            }
            
        }
                           
        vector<vector<int>> ans;
                           
        for(auto it : mp) {
            vector<int> val;
            for(auto q : it.second) {
                val.insert(val.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(val);
        }
        
        return ans;
    }
};