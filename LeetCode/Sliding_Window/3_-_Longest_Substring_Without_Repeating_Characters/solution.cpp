class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char, int> fq;
        int j=0;
        int len=0;

        for(int i=0; i<n; i++){
            fq[s[i]]++;

            while(fq[s[i]]>1){
                fq[s[j]]--;
                j++;
            }
            
            len=max(len, i-j+1);
        }

        return len;
    }
};