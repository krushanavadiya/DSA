class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        // adj[0]-->(1,100) 0 point karshe 1 ane cost to reach 1
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        //format of queue {stops(k stops), {current node, current cost}}
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;
       
        pq.push({0,{src,0}}); //queue ma k=0, curr_node=source, cost=0
        vector<int> costs(n, 1e9);
        costs[src] = 0; // cost to reach curr-node je atyare 0 che tyathi 0 pochvanu distance 0 che to cost pn 0

        while(!pq.empty()){
            // pair<int ,pair<int,int>> u=pq.top();

            int stops=pq.top().first; // haji apde move nthi karyu to apdo k==0
            int curr_node=pq.top().second.first;// source 0 che, to apdo current node 0 hashe atyare
            int cost=pq.top().second.second; // cost to reach 0 from 0 is = 0

            pq.pop();

            if (stops > k) continue;

            for(auto p1: adj[curr_node]){
                int v=p1.first;  //adj[0]-->{1,100} hatu to ema thi v point to 1
                int u=p1.second; //u points to cost to reach 1 means 100

                //if cost to reach city v from curr_node is > than the 0+100
                if(costs[v]>cost+u){ 
                    costs[v]= cost+u; //costs[1] is equal to 0+100 i.e. 100
                    pq.push({stops + 1, {v, costs[v]}}); // queue ma have next push ({0+1,{1,100}})
                }
            }
        }

        if(costs[dst]==1e9){
            return -1;
        }

        return costs[dst];

    }
};