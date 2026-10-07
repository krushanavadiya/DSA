class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>ans(n, vector<int>(m));

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j}, 0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int s=q.size();

            for(int i=0; i<s; i++){
                pair<pair<int, int>, int> p=q.front();
                int x=p.first.first;
                int y=p.first.second;
                int d=p.second;
                q.pop();

                ans[x][y]=d;

                if(x>=0 && x<n && y>0 && !vis[x][y-1] && mat[x][y-1]==1){
                    q.push({{x, y-1}, d+1});
                    vis[x][y-1]=1;
                }

                if(x>=0 && x<n && y<m-1 && !vis[x][y+1] && mat[x][y+1]==1){
                    q.push({{x, y+1}, d+1});
                    vis[x][y+1]=1;
                }

                if(x>0 && y>=0 && y<m && !vis[x-1][y] && mat[x-1][y]==1){
                    q.push({{x-1, y}, d+1});
                    vis[x-1][y]=1;
                }

                if(x<n-1 && y>=0 && y<m && !vis[x+1][y] && mat[x+1][y]==1){
                    q.push({{x+1, y}, d+1});
                    vis[x+1][y]=1;
                }
            }
        }

        return ans;
    }
};