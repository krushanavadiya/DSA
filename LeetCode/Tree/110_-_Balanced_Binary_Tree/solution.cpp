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
    bool isBalanced(TreeNode* root) {
        bool isbal=true;
        traverse(root, isbal);
        return isbal;
    }

    int traverse(TreeNode* root, bool& isbal){
        if(root==nullptr) return 0;

        int ld=traverse(root->left, isbal);
        int rd=traverse(root->right, isbal);

        if(abs(ld-rd)>1) isbal=false;

        return 1+max(ld,rd);
    }
};