class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<pair<int, int>> st;
        int sign=1;
        long long int sum=0;
        int i=0;
        while(i<n){
            if(isdigit(s[i])){
                long long int num=0;
                while(i<n && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i--;
                sum+=num*sign;
                sign=1;
            }
            else if(s[i]=='('){
                st.push({sum, sign});
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                int n1=st.top().first;
                int n2=st.top().second*sum;
                sum=n1+n2;
                st.pop();
            }
            else if(s[i]=='-'){
                sign=-1*sign;
            }
            i++;
        }

        return sum;
    }
};