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
    vector<int> postorder(Node* root) {
        Node* curr=root;
        vector<int> ans;
        traverse(curr, ans);
        return ans;
    }

    void traverse(Node* curr, vector<int>& ans){
        if(curr==nullptr) return;

        int n=curr->children.size();

        for(int i=0; i<n; i++){
            traverse(curr->children[i], ans);
        }

        ans.push_back(curr->val);
    }
};