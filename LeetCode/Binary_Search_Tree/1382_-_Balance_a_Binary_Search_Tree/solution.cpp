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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        traverse(root, arr);

        return create(arr,0,arr.size()-1);
    }

    void traverse(TreeNode* curr, vector<int>& arr){
        if(curr==nullptr) return;

        traverse(curr->left, arr);
        arr.push_back(curr->val);
        traverse(curr->right, arr);
    }

    TreeNode* create(vector<int>& arr, int l, int h){
        if(l>h) return nullptr;

        int mid=l+(h-l)/2;

        TreeNode* root=new TreeNode(arr[mid]);
        root->left=create(arr, l, mid-1);
        root->right=create(arr, mid+1, h);

        return root;
    }
};