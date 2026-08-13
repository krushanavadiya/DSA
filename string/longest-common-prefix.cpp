class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string prefix=strs[0]; //flower

        for(int i=1; i<n; i++){
            string s=strs[i];
            string ans="";
            
            for(int j=0; j<s.size(); j++){ 
                if(prefix[j]==s[j]){
                    ans+=s[j];
                }
                else{
                    break;
                }
            }    
            prefix=ans;    
        } 

        return prefix;  

    }
};