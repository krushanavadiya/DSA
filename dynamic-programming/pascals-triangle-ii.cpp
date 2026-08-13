class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;

        vector<vector<int>> ans(n+1);

        ans[0]={1};
        for(int i=1; i<=n; i++){
            vector<int> row(i+1,1);
            for(int j=1; j<i; j++){
                row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans[i]=row;
        }

        return ans[n];
    }
};