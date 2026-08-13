class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        int i=0; 
        stack<char> st;
        string str="";
        string ans="";

        while(i<n){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        if(st.empty()){
            return "0";
        }

        while(!st.empty()){
            str+=st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());

        int j=0;

        while(j<str.size()){
            if(str[j]!='0'){
                break;
            }
            j++;
        }

        while(j<str.size()){
            ans+=str[j];
            j++;
        }

        if(ans==""){
            return "0";
        }
        else{
            return ans;
        }
    }
};