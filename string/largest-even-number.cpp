class Solution {
public:
    string largestEven(string s) {
        int indextwo=-1;

        for(int i=0;i<s.size();i++){
            if(s[i]=='2'){
                indextwo=i;
            }
        }
        if(indextwo==-1) return "";

        return s.substr(0,indextwo+1);
    }
};