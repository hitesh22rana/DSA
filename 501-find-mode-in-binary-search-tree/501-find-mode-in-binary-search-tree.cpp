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

class comp {
public:
    bool operator()(pair<int,int>& p1, pair<int,int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int,int>& mp) {
        if(root == NULL) return;
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        inorder(root,mp);
        
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pq;
        
        for(auto& it : mp) {
            if(!pq.empty()) {
                if(pq.top().second < it.second) {
                    pq.pop();
                    pq.push(it);
                } else if(pq.top().second == it.second) {
                    pq.push(it);
                }
                
            } else {
                pq.push(it);
            }
        }
        
        pair<int,int> prev = pq.top();
        pq.pop();
        ans.push_back(prev.first);
        
        while(!pq.empty()) {
            if(prev.second <= pq.top().second) {
                ans.push_back(pq.top().first);
                pq.pop();
            } else {
                break;   
            }
        }
        
        return ans;
    }
};