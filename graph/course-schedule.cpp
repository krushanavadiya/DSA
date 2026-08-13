class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj= vector<vector<int>>(numCourses, vector<int>());

        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];

            adj[b].push_back(a);             
        }

        vector<int> visited(numCourses,false);
        vector<int> path(numCourses,false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)){
                    return false;
                }
            
            }
        }

        return true;

    }

    int ans=false;

    bool dfs(int i,vector<vector<int>>& adj, vector<int>& visited , vector<int>& path){
        visited[i]=path[i]=true;

        for(int next: adj[i]){
            if(!visited[next]){
                if(dfs(next,adj,visited,path)){
                    return true;
                }
            }

            else if(path[next]){
                return true;
            }
        }

        path[i]=false;
        return false;
    }
};