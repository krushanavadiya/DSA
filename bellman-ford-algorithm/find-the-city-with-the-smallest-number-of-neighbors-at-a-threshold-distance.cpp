class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        int minReachable = n;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, INT_MAX);

            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty()) {
                pair<int,int> u=pq.top();
                int d = u.first;
                int x = u.second;
                pq.pop();

                if (d > dist[x]) continue;

                for (auto& edge : adj[x]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (dist[x] + w < dist[v]) {
                        dist[v] = dist[x] + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= minReachable) {
                minReachable = count;
                ans = i;
            }
        }

        return ans;
    }
};