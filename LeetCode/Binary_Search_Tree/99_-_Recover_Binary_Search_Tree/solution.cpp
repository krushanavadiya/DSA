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
public:
    void recoverTree(TreeNode* root) {
        vector<int> val;
        vector<TreeNode*> node;

        traverse(root, val, node);

        sort(val.begin(), val.end());

        for(int i=0; i<val.size(); i++){
            node[i]->val=val[i];
        }

    }

    void traverse(TreeNode* curr, vector<int>& val, vector<TreeNode*>& node){
        if(curr==nullptr) return;

        traverse(curr->left, val, node);
        val.push_back(curr->val);
        node.push_back(curr);
        traverse(curr->right, val, node);
    }

};