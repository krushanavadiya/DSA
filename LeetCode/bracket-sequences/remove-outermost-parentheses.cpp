class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        // int count=0;

        string ans="";

        // for(int i=0; i<n; i++){
        //     if(s[i]=='('){
        //         if(count>0){
        //             ans+=s[i];
        //         }
        //         count++;
        //     }
        //     else{
        //         count--;
        //         if(count>0){
        //             ans+=s[i];
        //         }
        //     }
        // }

        // return ans;

        stack<char> st;
        int i=0;
        // int count=0;
        // while(i<n){
        //     if(s[i]=='('){
        //         if(count>0){
        //             ans+=s[i];
        //         }
        //         st.push(s[i]);
        //         count++;
        //     }
        //     else{
        //         count--;
        //         st.pop();
        //         if(count>0){
        //             ans+=s[i];
        //         }    
        //     }
        //     i++;
        // }

        while(i<n){
            if(s[i]=='('){
                if(!st.empty()){
                    ans+=s[i];
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans+=s[i];
                }
            }
            i++;
        }
        return ans;

    }
};