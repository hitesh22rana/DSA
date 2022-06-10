/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> val;
            
            for(int i = q.size() ; i>=1 ; i--) {
                Node* node = q.front();
                q.pop();
                val.push_back(node->val);
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
            
            if(val.size()) ans.push_back(val);
            
        }
        return ans;
    }
};