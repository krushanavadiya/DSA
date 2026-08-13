class Solution {
public:
    int r,c;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         r=grid.size();
         c=grid[0].size();
        int max_area=0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    max_area=max(max_area, dfs(i,j,grid));
                }
            }
        }

        return max_area;

    }



    int dfs(int i, int j, vector<vector<int>>&grid){
        
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1){
            return 0;
        }

        grid[i][j]=-1;
        int count=1;

        if(j>0 && grid[i][j-1]==1 ){
            count+=dfs(i,j-1,grid);
        }

        if(j<c-1 && grid[i][j+1]==1 ){
            count+=dfs(i,j+1,grid);
        }

        if(i>0 && grid[i-1][j]==1){
            count+=dfs(i-1,j,grid);
        }
        if(i<r-1 && grid[i+1][j]==1 ){
            count+=dfs(i+1,j,grid);
        }

        return count;
    }
};