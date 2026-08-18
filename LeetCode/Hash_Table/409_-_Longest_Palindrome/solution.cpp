class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char, int> fq;
        int odd=0;

        for(int i=0; i<n; i++){
            fq[s[i]]++;
            if(fq[s[i]]%2!=0){
                odd++;
            }
            else odd--;
        }
        
        if(odd>0) return n-(odd-1);
        return n;
    }
};