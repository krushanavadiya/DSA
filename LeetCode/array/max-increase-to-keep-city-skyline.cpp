class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dup=grid;

        vector<int> row(n);
        vector<int> col(m);

        for(int i=0; i<n; i++){
            int maxr=INT_MIN;
            for(int j=0; j<m; j++){
                maxr=max(maxr,grid[i][j]);
            }
            row[i]=maxr;
        }

        for(int i=0; i<m; i++){
            int maxc=INT_MIN;
            for(int j=0; j<n; j++){
                maxc=max(maxc,grid[j][i]);
            }
            col[i]=maxc;
        }

        int sum=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                grid[i][j]=min(row[i],col[j]);
                sum+=grid[i][j]-dup[i][j];
            }
        }

        return sum;
    }
};