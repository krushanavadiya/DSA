class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        stack<char> st;
        int i=1;
        st.push(s[0]);

        while(i<n){
            char curr=s[i];
            if(!st.empty() && st.top()==curr){
                st.pop();
            }
            else{
                st.push(curr);
            }
            i++;
        }

        string ans="";
        while(!st.empty()){
            char t=st.top();
            ans+=t;
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};