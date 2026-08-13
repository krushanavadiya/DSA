class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        pq.push({0,k});

        while(!pq.empty()){
            pair<int,int> u= pq.top();
            
            int d=u.first;
            int x=u.second;
            pq.pop();

            if (d > dis[x]) continue;

            for(auto p1: adj[x]){
                int v=p1.first;
                int w=p1.second;
                if(dis[v]>d+w){
                    dis[v]=d+w;
                    pq.push({dis[v],v});
                }

            }
        }

        int ans=0;
        for(int i=1; i<n+1; i++){
            ans=max(ans, dis[i]);
        }
        
        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};