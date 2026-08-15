class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> fq;

        for(int i=0; i<s.size(); i++){
            fq[s[i]]++;
        }

        char c;

        for(int i=0; i<t.size(); i++){
            fq[t[i]]--;
            if(fq[t[i]]==-1){
                c=t[i];
            }
        }

        return c;
    }
};