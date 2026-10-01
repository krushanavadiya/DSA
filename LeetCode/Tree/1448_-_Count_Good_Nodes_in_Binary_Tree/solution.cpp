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
    int goodNodes(TreeNode* root) {
        int c=0;
        traverse(root, c, root->val);

        return c;
    }

    void traverse(TreeNode* curr, int& c, int num){
        if(curr==nullptr) return;

        if(curr->val>=num){
            c++;
            num=curr->val;
        } 
        

        traverse(curr->left, c, num);
        traverse(curr->right,c, num);
    }
};