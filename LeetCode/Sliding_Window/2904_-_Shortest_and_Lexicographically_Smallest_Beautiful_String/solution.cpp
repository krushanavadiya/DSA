class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();

        unordered_map<char, int> fq;
        int j=0;
        string ans="";

        for(int i=0; i<n; i++){
            if(s[i]=='1') fq[s[i]]++;;

            while(fq['1']==k){
                string st=s.substr(j, i-j+1);
                if(ans.empty()) ans=st;
                else if(ans.size()>st.size()) ans=st;
                else if(st.size()>ans.size()) ans=ans;
                else ans=min(ans, st);

                if(s[j]=='1') fq[s[j]]--;
                j++;
            }
        }

        return ans;
    }
};