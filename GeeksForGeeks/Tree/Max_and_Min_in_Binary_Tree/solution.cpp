/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int maxnum=INT_MIN;
    int minnum=INT_MAX;
     
    int findMax(Node *root) {
        // code here
        
        traverse(root, maxnum, minnum);
        return maxnum;
    }

    int findMin(Node *root) {
        // code here
       
        traverse(root, maxnum, minnum);
        return minnum;
    }
    
    void traverse(Node* root, int& maxnum, int& minnum){
        if(root==nullptr) return;
        
        maxnum=max(maxnum, root->data);
        minnum=min(minnum, root->data);
        
        traverse(root->left, maxnum, minnum);
        traverse(root->right, maxnum, minnum);
    }
};