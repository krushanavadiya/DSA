class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        char prev='+';
        int curr=0;

        stack<int> st;

        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                curr=curr*10+(s[i]-'0');
            }
            if((s[i]<'0' || s[i]>'9') && s[i] != ' '|| i==n-1){
                if(prev=='+'){
                    st.push(curr);
                }
                else if(prev=='-'){
                    st.push(-curr);
                }
                else if(prev=='*'){
                    int c=st.top();
                    st.pop();
                    st.push(curr*c);
                }
                else if(prev=='/'){
                    int c=st.top();
                    st.pop();
                    st.push(c/curr);
                }

                prev=s[i];
                curr=0;
            }   
        }

        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};