class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(i<=n+10){
            string s=to_string(i);
            int pro=1;
            for(int j=0; j<s.size(); j++){
                pro=pro*(s[j]-'0');
            }

            if(pro%t==0){
                break;
            }

            i++;
        }

        return i;
    }
};