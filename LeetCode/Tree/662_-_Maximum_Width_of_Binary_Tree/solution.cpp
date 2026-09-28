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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;

        queue<pair<TreeNode* , long long int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n=q.size();
            long long int minIdx=q.front().second;
            long long first, last;

            for(int i=0; i<n; i++){
                long long int curr=q.front().second-minIdx;
                TreeNode* p=q.front().first;
                q.pop();

                if(i==0) first=curr;
                if(i==n-1) last=curr;

                if(p->left!=nullptr){
                    q.push({p->left, (2*curr)+1});
                }

                if(p->right!=nullptr){
                    q.push({p->right, (2*curr)+2});
                }
            }

            ans=max(ans, (int)(last-first+1));
        }

        return ans;
    }
};