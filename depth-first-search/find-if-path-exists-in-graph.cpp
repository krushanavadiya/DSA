class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj=vector<vector<int>>(n,vector<int>());

        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> visited(n,0);

     //   return dfs(adj,source,destination,visited);

        //BFS
        queue<int> q;
        visited[source]=1;
        q.push(source);

        while(!q.empty()){
            int u=q.front();
            q.pop(); //pela apde source 1 lidho to have e source na adjacent elements traverse thase ane 1 pop thase
            visited[u]=1;

            if(u==destination){
                return true;
            }

            for(int x:adj[u]){
                if(visited[x]==0){
                    q.push(x);
                }
            }

        }
        return false;

    }

    // int ans=false;
    // bool dfs(vector<vector<int>>& adj, int source, int destination, vector<int>& visited){

    //     if(source==destination){
    //         return true;
    //     }

    //     if(visited[source]==1){
    //         return false;
    //     }

    //     visited[source]=1;

    //     //source na adjacent elements mate loop
    //     for(int x:adj[source]){
    //         ans= ans|dfs(adj,x,destination,visited);
    //     }

    //     return ans;
    // }
};