class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;

        vector<vector<int>> adj(n);

        for(int i=0; i<m; i++){
            int a=connections[i][0];
            int b=connections[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(n, false);

        int cable=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i]=true;
                cable++;

                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int curr=q.front();
                    q.pop();

                    for(auto neighbour: adj[curr]){
                        if(!vis[neighbour]){
                            vis[neighbour]=true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }

        return cable-1;

    }
};