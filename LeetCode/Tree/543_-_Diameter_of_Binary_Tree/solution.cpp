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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        traverse(root, ans);
        return ans;
    }

    int traverse(TreeNode* curr, int& ans){
        if(curr==nullptr) return 0;

        int left=traverse(curr->left, ans);
        int right=traverse(curr->right, ans);

        ans=max(ans, left+right);

        return max(left, right)+1;
    }
};