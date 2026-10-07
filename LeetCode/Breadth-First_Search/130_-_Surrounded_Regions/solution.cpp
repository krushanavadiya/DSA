class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<int, int>> q;

        int count=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(((i==0 || i==n-1) || (j==0 || j==m-1)) && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int s=q.size();

            for(int i=0; i<s; i++){
                pair<int, int> p= q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                
                    if(x>=0 && x<n && y<m-1 && !vis[x][y+1] && board[x][y+1]=='O'){
                        q.push({x, y+1});
                        vis[x][y+1]=1;
                    }

                    if(x>=0 && x<n && y>0 && !vis[x][y-1] && board[x][y-1]=='O'){
                        q.push({x, y-1});
                        vis[x][y-1]=1;
                    }

                    if(x>0 && y>=0 && y<m && !vis[x-1][y] && board[x-1][y]=='O'){
                        q.push({x-1, y});
                        vis[x-1][y]=1;
                    }

                    if(x<n-1 && y>=0 && y<m && !vis[x+1][y] && board[x+1][y]=='O'){
                        q.push({x+1, y});
                        vis[x+1][y]=1;
                    }
                
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};