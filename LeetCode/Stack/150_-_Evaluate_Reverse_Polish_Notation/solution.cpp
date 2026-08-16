class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();

        stack<int> st;

        int i=0;

        while(i<n){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int n2=st.top();
                st.pop();
                int n1=st.top();
                st.pop();

                if(tokens[i]=="+") st.push(n1+n2);
                else if(tokens[i]=="-") st.push(n1-n2);
                else if(tokens[i]=="*") st.push(n1*n2);
                else st.push(n1/n2);
            }
            i++;
        }

        return st.top();
    }
};