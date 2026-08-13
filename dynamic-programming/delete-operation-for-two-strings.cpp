class Solution {
public:
    int minDistance(string word1, string word2) {
        int i,j;
        int n1=word1.size();
        int n2=word2.size();

    if(n1==0 || n2==0){
        return 0;
    }
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
    for(i=1;i<=n1;i++){
        for(j=1;j<=n2;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }

            else {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    return (n1-dp[n1][n2])+(n2-dp[n1][n2]);
    }
};