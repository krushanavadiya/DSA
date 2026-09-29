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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return {};
        vector<vector<int>> ans;
        vector<int> arr;
        int sum=0;

        traverse(root, targetSum, ans, arr, sum);

        return ans;
    }

    void traverse(TreeNode* curr, int targetSum, vector<vector<int>>& ans, vector<int>& arr, int sum){
        if(curr==nullptr) return;

        arr.push_back(curr->val);
        sum+=curr->val;

        if(curr->left==nullptr && curr->right==nullptr){
            if(sum==targetSum){
                ans.push_back(arr);
            }
        }
        else{
            traverse(curr->left, targetSum, ans, arr, sum);
            traverse(curr->right, targetSum, ans, arr, sum);
        }

        arr.pop_back();
    }
};