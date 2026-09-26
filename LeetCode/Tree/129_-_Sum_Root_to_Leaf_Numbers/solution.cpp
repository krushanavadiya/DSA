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
    int ans=0;
    int sumNumbers(TreeNode* root) {
        int sum=0;
        traverse(root, sum);
        return ans;
    }

    void traverse(TreeNode* curr, int sum){
        if(curr==nullptr) return;

        sum=(sum*10)+curr->val;

        if(curr->left==nullptr && curr->right==nullptr){
            ans+=sum;
        }

        traverse(curr->left, sum);
        traverse(curr->right, sum);
    }
};