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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int n=nums.size();
        int l=0, r=n-1;
        int mid=l+(r-l)/2;

        TreeNode* root= new TreeNode(nums[mid]);
        root->left=getNode(nums, l, mid-1);
        root->right=getNode(nums, mid+1, r);

        return root;
    }

    TreeNode* getNode(vector<int>& nums, int low, int high){
        if(low>high) return nullptr;

        int mid=low+(high-low)/2;

        TreeNode* root=new TreeNode(nums[mid]);
        root->left=getNode(nums, low, mid-1);
        root->right=getNode(nums, mid+1, high);

        return root;
    }
};