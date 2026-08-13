class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj= vector<vector<int>>(n,vector<int>());
        vector<int> indegree(n,0);
        vector<int> res;

        for(int i=0; i<n-1; i++){
            int a=edges[i][0];
            int b=edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        while(q.empty()==false){
            int n=q.size();
            
            res.clear();
           
            while (n--) {
                int u=q.front();
                q.pop();

                res.push_back(u);
                for(int v: adj[u]){
                    indegree[v]--;

                    if(indegree[v]==1){
                        q.push(v);
                    }
                }
            }    
        }

        return res;

    }
};