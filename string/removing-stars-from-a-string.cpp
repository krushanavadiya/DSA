class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        stack<char> st;
        int i=0;

        while(i<n){
            
            if(s[i]>='a' && s[i]<='z'){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top()>='a' && st.top()<='z' && s[i]=='*'){
                st.pop();
            }
            i++;
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};