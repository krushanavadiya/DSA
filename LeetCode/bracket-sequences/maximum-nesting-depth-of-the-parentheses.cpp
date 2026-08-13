class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int depth=0;

        int c1=0;
        int c2=0;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                c1++;
            }
            if(s[i]==')'){
                c2++;
            }
            if(s[i]=='+' || s[i]=='-'|| s[i]=='*' || s[i]=='/'|| '0'<=s[i]<='9'){
                depth=max(depth, c1-c2);
            }
        }
        return depth;
    }
};