class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        if(n1!=n2){
            return false;
        }

        unordered_map<char, char> freq1;
        unordered_map<char, char> freq2;

        for(int i=0; i<n1; i++){
            if(freq1.contains(s[i])){
                if(freq1[s[i]]==t[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
            if(freq2.contains(t[i])){
                if(freq2[t[i]]==s[i]){
                    continue;
                }
                else{
                    return false;
                }
            }

            else{
                freq1[s[i]]=t[i];
                freq2[t[i]]=s[i];
            }
        }

        return true;
    }
};