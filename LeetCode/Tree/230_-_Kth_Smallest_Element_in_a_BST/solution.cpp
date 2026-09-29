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
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int ans=-1;

        traverse(root, c, k, ans);
        return ans;
    }

    void traverse(TreeNode* curr, int& c, int k, int& ans){
        if(curr==nullptr) return ;

        traverse(curr->left, c, k, ans);
        
        c++;
        if(c==k){
            ans=curr->val;
            return;
        }

        traverse(curr->right, c, k, ans);
    }
};