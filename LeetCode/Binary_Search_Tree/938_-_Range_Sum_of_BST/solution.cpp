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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        traverse(root, low, high, sum);

        return sum;
    }

    void traverse(TreeNode* curr, int l, int h, int& sum){
        if(curr==nullptr) return;

        if(curr->val>=l && curr->val<=h){
            sum+=curr->val;
            traverse(curr->left, l, h, sum);
            traverse(curr->right, l, h, sum);
        }

        if(curr->val<l){
            traverse(curr->right, l, h, sum);
        }

        if(curr->val>h){
            traverse(curr->left, l, h, sum);
        }

    }
};