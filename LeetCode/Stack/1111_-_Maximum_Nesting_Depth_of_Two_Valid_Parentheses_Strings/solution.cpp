class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int> ans;

        stack<char> st;

        for(int i=0; i<n; i++){
            if(seq[i]=='('){
                st.push(seq[i]);
                ans.push_back(st.size()%2);
            }
            if(seq[i]==')'){
                ans.push_back(st.size()%2);
                st.pop();
            }   
        }

        return ans;
    }
};