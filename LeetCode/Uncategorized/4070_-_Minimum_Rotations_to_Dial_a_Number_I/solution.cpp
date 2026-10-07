class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int ans=0;
        char k='0';
        
        for(int i=0; i<n; i++){
            int diff=abs(s[i]-k);
            ans+=min(10-diff, diff);
            k=s[i];
        }

        return ans;
    }
};

