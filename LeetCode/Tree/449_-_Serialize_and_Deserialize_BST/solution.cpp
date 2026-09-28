/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st="";
        traverse(root, st);
        return st;
    }

    void traverse(TreeNode* curr, string& st){
        if(curr==nullptr) return;

        st+=(to_string(curr->val)+"_");

        traverse(curr->left, st);
        traverse(curr->right, st);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string p;
        queue<int> q;

        while(getline(ss, p, '_')){
            if(!p.empty()) q.push(stoi(p));
        }


        return tree(q, INT_MIN, INT_MAX);
    }

    TreeNode* tree(queue<int>& q, int min, int max){
        if(q.empty()) return nullptr;

        int val=q.front();

        if(val<min) return nullptr;
        if(val>max) return nullptr;

        q.pop();
        TreeNode* root=new TreeNode(val);

        root->left=tree(q, min, val);
        root->right=tree(q, val, max);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;