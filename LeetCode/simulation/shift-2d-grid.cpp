class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       
        int n=grid.size();
        int m=grid[0].size();
        while(k>0){
            vector<vector<int>> dup=grid;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(j==m-1 && i+1<n){
                        grid[i + 1][0]=dup[i][m - 1];
                    }
                    else if(i==n-1 && j==m-1){
                        grid[0][0]=dup[n - 1][m - 1];
                    }
                    else if(j<m-1){
                        grid[i][j + 1]=dup[i][j];
                    }
                }
            }
            k--;
        }

        return grid;
    }
};