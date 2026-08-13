class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        
        queue<pair<int,int>> q;
        
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited( n,vector<int>(m,0));
        
        int count1=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1)count1++;
            }
        }
        
        while(!q.empty() && count1 > 0){
            
            int s = q.size();
            count++;
            for(int i=0;i<s;i++){
                pair<int,int>  p =  q.front();
                q.pop();
                int x = p.first;
                int y= p.second;
                if( !visited[x][y] ){
                    
                    if(x+1 < n  && x+1 >=0 && y>=0 && y<m && grid[x+1][y] == 1){
                        grid[x+1][y] = 2;
                        q.push({x+1,y});
                        count1--;
                        
                    }
                    if(x-1 < n  && x-1 >=0 && y>=0 && y<m && grid[x-1][y] == 1){
                        grid[x-1][y] = 2;
                        q.push({x-1,y});
                        count1--;
                        
                    }
                    if((x < n  && x >=0) && (y + 1>=0 && y+1<m) && grid[x][y+1] == 1){

                        grid[x][y+1] = 2;
                        q.push({x,y+1});count1--;
                        
                    }
                    if( x < n  && x >=0 && y - 1>=0 && y - 1<m && grid[x][y-1] == 1){
                        grid[x][y-1] = 2;
                        q.push({x,y-1});count1--;
                    }
                    
                    visited[x][y] = true;
                    
            }
            }
        }
        
        if(q.empty() && count1>0)return -1;
        return count;
    }
};