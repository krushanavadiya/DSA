class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n1=s.size();
        string s_rev=s;
        reverse(s.begin(),s.end());
        int n2=s_rev.size();

        if(n1==0 || n2==0){
            return 0;
        }
        int i,j;
        vector<vector<int>>  dp(n1+1, vector<int>(n2+1, 0));
        

        for(i=1;i<=n1;i++){
        for(j=1;j<=n2;j++){
            if(s[i-1]==s_rev[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }

            else {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    return dp[n1][n2];

        


    }
};