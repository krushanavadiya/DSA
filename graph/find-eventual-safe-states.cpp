class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj=vector<vector<int>>(n,vector<int>());
        vector<int> indegree(n,0);
        vector<int> topo;

        for(int i=0; i<graph.size();i++){
            for(int j=0; j<graph[i].size();j++){

                //reverse the graph to find the outdegree=0
                adj[graph[i][j]].push_back(i);

                indegree[i]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(q.empty()==false){
            int u=q.front();
            q.pop();

            topo.push_back(u);

            for(int v: adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        sort(topo.begin(),topo.end());

        return topo;
        
    }
};