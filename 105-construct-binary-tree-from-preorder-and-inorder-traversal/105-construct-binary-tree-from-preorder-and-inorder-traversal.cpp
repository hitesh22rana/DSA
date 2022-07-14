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
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right, int& preorderIndex, unordered_map<int, int>& inorderIndexMap) {
        if(left > right) return NULL;
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        
        root->left = arrayToTree(preorder, left, inorderIndexMap[rootValue]-1, preorderIndex, inorderIndexMap);
        root->right = arrayToTree(preorder, inorderIndexMap[rootValue]+1, right, preorderIndex, inorderIndexMap);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        int preorderIndex = 0;
        
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] =  i;
        }

        return arrayToTree(preorder, 0, preorder.size() - 1, preorderIndex, inorderIndexMap);
    }    
};