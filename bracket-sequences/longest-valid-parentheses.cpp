class Solution {
public:
    int longestValidParentheses(string s) {
        // int count=0;
        // int n=s.size();

        // for(int i=0; i<n; i++){
        //     if(s[i]=='('){
        //         count++;
        //     }
        //     if(s[i]=='('){
        //         count--;
        //     }
        // }

        // return n-count;

        int n=s.size();
        stack<int> st;
        int len=0;

        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                    if(st.empty()){
                        len=max(len, i+1);
                    }
                    else{
                        len=max(len, i-st.top());
                    }
                }
                else{
                    st.push(i);
                }
            }

            i++;
        }

        return len;
    }
};