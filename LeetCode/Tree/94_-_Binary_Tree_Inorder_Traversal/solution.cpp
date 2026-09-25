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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        traverse(curr, ans);
        return ans;
    }

    void traverse(TreeNode* curr, vector<int>& ans){
        if(curr==nullptr) return;

        traverse(curr->left, ans);
        ans.push_back(curr->val);
        traverse(curr->right, ans);
    }
};