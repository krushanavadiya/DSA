class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);

        string st="";
        for(int i=0; i<s.size(); i++){
            if(s[i]!='0'){
                st+=s[i];
            }
        }

        if(s.empty()){
            return 0;
        }

        long long sum=0;
        for(int i=0; i<st.size(); i++){
            sum+=st[i]-'0';
        }    
        
        long long num=0;

        for(int i=0; i<st.size(); i++){
            num=num*10+(st[i]-'0');
        }
        
        return num*sum;
    }
};