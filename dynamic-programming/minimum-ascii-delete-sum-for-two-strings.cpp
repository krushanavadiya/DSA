class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int i,j;
        int n1=s1.size();
        int n2=s2.size();
        int len=0;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
        for(i=1;i<=n1;i++){
            for(j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }

                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        int total = 0;
        for (char c : s1) total += c;
        for (char c : s2) total += c;

        return total - 2 * dp[n1][n2];

    }
};