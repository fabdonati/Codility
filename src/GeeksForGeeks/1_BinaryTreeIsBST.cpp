#include <iostream>

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int isBSTUtil(Node* node, int min, int max);
int isBST(Node *node) {
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(Node* node, int min, int max) {
    if (node == NULL) {
        return 1;
    }

    if (node->data < min || node->data > max) {
        return 0;
    }

    return 
        isBSTUtil(node->left, min, node->data-1)  &&
        isBSTUtil(node->right, node->data+1, max);
}

int main() {
    Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
          
    std::cout << "Binary tree is" << (isBST(root) ? "" : " not") << " a BST";

    return 0;
}