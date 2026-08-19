class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> ans;

        int t=0, b=n-1, l=0, r=m-1;

        while(t<=b && l<=r){
            for(int i=l; i<=r; i++){
                ans.push_back(matrix[t][i]);
            }
            t+=1;

            for(int j=t; j<=b; j++){
                ans.push_back(matrix[j][r]);
            }
            r-=1;

            if(t<=b){
                for(int k=r;k>=l; k--){
                    ans.push_back(matrix[b][k]);
                }
                b-=1;
            }

            if(l<=r){
                for(int v=b; v>=t; v--){
                    ans.push_back(matrix[v][l]);
                }
                l+=1;
            }
        }
        return ans;
    }
};