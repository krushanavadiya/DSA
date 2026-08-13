class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=n-1, j=n-1;
        vector<string> a;
        string ans="";

        // while(i>=0 && j>=0){
        //     if(s[i]!=' '){
        //         i--;
        //     }
        //     if(s[i]==' '){
        //         if(ans==''){
        //             for(int k=i+1; k<=j; k++){
        //                 ans+=s[k];
        //             }
        //             i--;
        //             j=i;
        //         }
        //         if(ans!=' '){
        //             if(s[i+1]==' '){
        //                 i--;
        //                 j=i;
        //             }
        //             else{
        //                 ans+=' ';
        //                 for(int k=i+1; k<=j; k++){
        //                     ans+=s[k];
        //                 }
        //                 i--;
        //                 j=i;
        //             }
        //         }
                
        //     }
        // }
        string st="";
        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                st+=s[i];
            }
            else{
                if(st.empty()){
                    continue;
                }
                else{
                    a.push_back(st);
                    st="";
                }       
            }
        }

        if(!st.empty()){
            a.push_back(st);
        }
        
        for(int i=a.size()-1; i>=0; i--){
            ans+=a[i];
            ans+=' ';
        }

        if(!ans.empty()){
            ans.pop_back();
        }
        
        return ans;
    }
};