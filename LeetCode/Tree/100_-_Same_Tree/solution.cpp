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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> q1;
        traverse(p, p1);
        traverse(q, q1);

        return p1==q1? true : false;
    }

    void traverse(TreeNode* curr, vector<int>& arr){
        if(curr==nullptr) {
            arr.push_back(100000);
            return;
        }
        
        arr.push_back(curr->val);
        traverse(curr->left, arr);
        traverse(curr->right, arr);
    }
};