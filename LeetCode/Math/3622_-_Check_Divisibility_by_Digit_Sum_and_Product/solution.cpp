class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int size=s.size();

        long long sum=0;
        for(int i=0; i<size; i++){
            sum+=(s[i]-'0');
        }

        long long prod=1;
        for(int i=0; i<size; i++){
            prod*=(s[i]-'0');
        }

        return n%(sum+prod)==0?true: false;
    }
};