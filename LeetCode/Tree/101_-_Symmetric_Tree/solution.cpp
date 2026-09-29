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
    bool isSymmetric(TreeNode* root) {
        vector<int> pr;
        vector<int> po;
        preOrder(root->left, pr);
        postOrder(root->right, po);

        reverse(pr.begin(), pr.end());
        return po==pr;
    }

    void preOrder(TreeNode* curr, vector<int>& pr){
        if(curr==nullptr){
            pr.push_back(1000);
            return;
        }

        pr.push_back(curr->val);
        preOrder(curr->left, pr);
        preOrder(curr->right, pr);
    }

    void postOrder(TreeNode* curr, vector<int>& po){
        if(curr==nullptr) {
            po.push_back(1000);
            return;
        }

        postOrder(curr->left, po);
        postOrder(curr->right, po);
        po.push_back(curr->val);
    }
};