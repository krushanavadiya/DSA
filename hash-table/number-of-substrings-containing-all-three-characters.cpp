class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char, int> fq;
        int count=0;

        int i=0, j=0;

        while(j<=n){
            fq[s[j]]++;

            while(fq.size()==3){
                count+=(n-j);
                fq[s[i]]--;
                if(fq[s[i]]==0){
                    fq.erase(s[i]);
                   
                }
                i++;
            }

            j++;
        }
        return count;
    }
};