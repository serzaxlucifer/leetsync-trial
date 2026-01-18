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
        if (root == nullptr) {
            return root;
        }
        
        queue<Node*> levelOrder;
        levelOrder.push(root);
        Node* previous = nullptr;

        while(!levelOrder.empty()) {
            int frontierSize = levelOrder.size();
            for (int i = 0; i < frontierSize; i++) {
                Node* node = levelOrder.front();
                levelOrder.pop();
                node->next = previous;

                if (node->right != nullptr) {
                    levelOrder.push(node->right);
                }

                if (node->left != nullptr) {
                    levelOrder.push(node->left);
                }

                previous = node;
            }
            previous = nullptr;
        }

        return root;
    }
};