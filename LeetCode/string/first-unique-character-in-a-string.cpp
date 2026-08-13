class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char, int> fq;

        for(int i=0; i<n; i++){
            fq[s[i]]++;
        }

        for(int i=0; i<n; i++){
            if(fq[s[i]]==1) {
                return i;
            }
        }

        return -1;
    }
};