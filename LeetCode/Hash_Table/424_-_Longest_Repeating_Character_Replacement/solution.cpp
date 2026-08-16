class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        unordered_map<char, int> fq;
        int fqmax=INT_MIN;
        int len=INT_MIN;
        int j=0;

        for(int i=0; i<n; i++){
            fq[s[i]]++;

            fqmax=max(fqmax, fq[s[i]]);

            while((i-j+1)- fqmax>k){
                fq[s[j]]--;
                j++;
            }

            len=max(len, i-j+1);
        }

        return len;
    }
};