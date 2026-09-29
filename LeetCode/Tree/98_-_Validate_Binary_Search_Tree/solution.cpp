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
    bool isValidBST(TreeNode* root) {
        
        return validate(root, nullptr, nullptr);;
    }

    bool validate(TreeNode* curr, TreeNode* min, TreeNode* max){
        if(curr==nullptr) return true;
        
        if((min!=nullptr && curr->val<=min->val)||(max!=nullptr && curr->val>=max->val)){
            return false;
        }

        return validate(curr->left, min, curr)&&validate(curr->right, curr, max);
    }
};