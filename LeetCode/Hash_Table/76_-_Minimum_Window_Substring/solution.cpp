class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int count=m;
        int len=INT_MAX;
        int st=0;
        unordered_map<char, int> fq;

        for(int i=0; i<m; i++){
            fq[t[i]]++;
        }

        int i=0, j=0;

        while(i<n){
            if(fq[s[i]]>0){
                count--;
            }
            fq[s[i]]--;
            i++;

            while(count==0){
                if(i-j<len){
                    len=i-j;
                    st=j;
                }
                
                fq[s[j]]++;
                if(fq[s[j]]>0) count++;
                j++;
            }
        }

        return len==INT_MAX? "": s.substr(st, len);
    }
};