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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr) return {};
        vector<string> ans;
        string st="";
        traverse(root, ans, st);
        
        return ans;
    }

    void traverse(TreeNode* curr, vector<string>& ans, string s){
        s+=to_string(curr->val);
        if(curr->right==nullptr && curr->left==nullptr){
            ans.push_back(s);
            return;
        }

        s+="->";

        if(curr->left!=nullptr) traverse(curr->left, ans, s);
        if(curr->right!=nullptr) traverse(curr->right, ans, s);
    }
};