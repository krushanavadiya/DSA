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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        bool ltor=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> curr;

            for(int i=0; i<size; i++){
                TreeNode* n=q.front();
                q.pop();

                curr.push_back(n->val);

                if(n->left!=nullptr){
                    q.push(n->left);
                }
                if(n->right!=nullptr){
                    q.push(n->right);
                }
            }
            if(ltor==false){
                reverse(curr.begin(), curr.end());
            }
            ltor=!ltor;
            ans.push_back(curr);
        }

        return ans;
    }
};