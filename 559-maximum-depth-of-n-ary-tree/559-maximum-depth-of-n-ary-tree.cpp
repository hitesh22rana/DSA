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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        
        int depth = 0;
        queue<Node *> q;
        q.push(root); 
        
        while(!q.empty()) {
            int n = q.size();
            depth++;
            
            while(n > 0) {
            
                Node * p = q.front();
                q.pop();

                for (int i = 0 ; i<p->children.size() ; i++) {
                    q.push(p->children[i]);   
                }
            
                n--;
            }
        }
        
        return depth;
    }
};