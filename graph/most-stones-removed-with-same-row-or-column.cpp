class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int components=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                components++;
                dfs(i,vis,stones,n);
            }
        }

        return n-components;
    }

    void dfs(int i, vector<int>& vis, vector<vector<int>>& stones, int n){
        vis[i]=1;

        for(int j=0; j<n; j++){
            if(!vis[j]){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dfs(j,vis,stones,n);
                }
            }
        }

    }
};
