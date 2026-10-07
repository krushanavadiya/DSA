class Solution {
public:
    int minRotations(int n, string s) {
        int ans=0;
        int curr='0';
        vector<int> pref(n+1, 0);
        
        for(int i=0; i<n; i++){
            int diff=abs(s[i]-curr);
            pref[i+1]=pref[i]+min(diff, 10-diff);
            curr=s[i];
        }

        vector<int> suff(n+1, 0);

        for(int i=n-2; i>=0; i--){
            int diff=abs(s[i]-s[i+1]);
            suff[i]=suff[i+1]+min(diff, 10-diff);
        }

        ans=pref[n];

        for(int i=0; i<n; i++){
            char c=(i==0)?'0':s[i-1];
    
            int diff=abs(c-(s[n-1]));
            int total=pref[i]+min(10-diff, diff)+suff[i];

            ans=min(total, ans);
        }

        return ans;
    }
};