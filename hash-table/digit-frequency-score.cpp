class Solution {
public:
    int digitFrequencyScore(int n) {
        string st=to_string(n);
        int m=st.size();

        unordered_map<char, int> fq;

        for(int i=0; i<m; i++){
            fq[st[i]]++;
        }

        int ans=0;
        
        for(auto ch: fq){
            int num=ch.first - '0';
            ans+=(num * ch.second);
        }

        return ans;
    }
};