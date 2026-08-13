class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        stack<char> st;
        int i=0;
        string ans="";
        
        while(i<n){
            if(s[i]>='a' && s[i]<='z'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
            i++;
        }

        if(st.empty()){
            return "";
        }
        else{
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};