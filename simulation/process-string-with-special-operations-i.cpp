class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string result="";

        for(int i=0; i<n; i++){
            if(s[i]>=97 && s[i]<=122){
                result+=s[i];
            }
            else if(s[i]=='*'){
                result=result.substr(0, result.size()-1);
            }
            else if(s[i]=='#'){
                result+=result;
            }
            else {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};