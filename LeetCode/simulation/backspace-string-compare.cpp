class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        stack<char> st1;
        stack<char> st2;

        int i=0;
        while(i<n){
            if(s[i]=='#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(s[i]);
            }
            i++;
        }

        int j=0;
        while(j<m){
            if(t[j]=='#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(t[j]);
            }
            j++;
        }

        string s1="";
        while(!st1.empty()){
            s1+=st1.top();
            st1.pop();
        }

        string t1="";
        while(!st2.empty()){
            t1+=st2.top();
            st2.pop();
        }

        reverse(s1.begin(), s1.end());
        reverse(t1.begin(),t1.end());

        if(s1==t1){
            return true;
        }
        else{
            return false;
        }
    }
};