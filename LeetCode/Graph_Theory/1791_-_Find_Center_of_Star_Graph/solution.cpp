class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // vector<vector<int>> adj=vector<vector<int>>(n,vector<int>());
        // vector<int> a(n,0);
        // vector<int> b(n,0);
        // int degree=0;
        // for(int i=0;i<edges.size();i++){
        //     for(int j=0;j<edges[0].size();j++){
        //         a[i]=edges[i][0];
        //         b[i]=edges[i][1];
        //     }
        // }

        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0]
        [1];
    }
};

