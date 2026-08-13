class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int peri=0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    if(j>0 && grid[i][j-1]==0 || j==0 ){
                        peri++;
                    }
                    if(j<c-1 && grid[i][j+1]==0 || j==c-1){
                        peri++;
                    }
                    if(i>0 && grid[i-1][j]==0 || i==0 ){
                        peri++;
                    }
                    if(i<r-1 && grid[i+1][j]==0 || i==r-1){
                        peri++;
                    }
                }
            }
        }

        return peri;
    }
};