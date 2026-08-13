class Solution {
public:
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (ll) 1e9+7;
        vector<vector<pair<ll,ll>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,1e18);
        vector<ll> ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto i:adj[node]){
                ll nextdis = i.second;
                ll adjacent = i.first;
                
                if(dist[adjacent]==dis+nextdis){
                    ways[adjacent]=(ways[adjacent]+ways[node])%mod;
                }

                if(dist[adjacent]>dis+nextdis){
                    dist[adjacent]= dis+nextdis;
                    ways[adjacent]=ways[node];
                    pq.push({dist[adjacent],adjacent});
                }
            }
        }
        return ways[n-1]%mod;
    }
};