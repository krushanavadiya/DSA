/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int getSize(Node* root) {
        // code here
        int size=0;
        traverse(root, size);
        return size;
    }
    
    void traverse(Node* root, int& size){
        if(root==nullptr) return;
        size++;
        traverse(root->left, size);
        traverse(root->right, size);
    }
};
