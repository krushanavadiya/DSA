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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        unordered_map<int, int> fq;
        traverse(root, arr, fq);

        for(int i=0; i<arr.size(); i++){
            int rem=k-arr[i];
            if(fq.find(rem)!=fq.end()){
                if(rem==arr[i] && fq[rem]%2==0) return true;
                if(rem!=arr[i] && fq[rem]>0) return true;
            }
        }

        return false;
    }

    void traverse(TreeNode* curr, vector<int>& arr, unordered_map<int, int>& fq){
        if(curr==nullptr) return;

        traverse(curr->left, arr, fq);
        arr.push_back(curr->val);
        fq[curr->val]++;
        traverse(curr->right, arr, fq);
    }

};