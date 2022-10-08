/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        
        queue<Node*> q;
        Node* head = root;
        q.push(head);
        
        while(!q.empty()) {
            int n = q.size();
            queue<Node*> levelOrderNodes;
                        
            for(int i = 0 ; i<n ; i++) {
                Node* node = q.front();
                q.pop();
                
                levelOrderNodes.push(node);
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }

                                    
            while(!levelOrderNodes.empty()) {
                Node* first = levelOrderNodes.front();
                levelOrderNodes.pop();
                                
                if(!levelOrderNodes.size()) {
                    first->next = NULL;
                    break;
                }
                                
                Node* second = levelOrderNodes.front();
                
                first->next = second;
            }
            
        }
        
        return head;
    }
};