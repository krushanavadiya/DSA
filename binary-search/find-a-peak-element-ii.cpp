class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int l=0, r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            int col=0;

            for(int i=0; i<m; i++){
                if(mat[mid][i]>mat[mid][col]){
                    col=i;
                }
            }

            int curr=mat[mid][col];

            int top=-1;
            if(mid>0){
                top=mat[mid-1][col];
            }

            int bottom=-1;
            if(mid<n-1){
                bottom=mat[mid+1][col];
            }

            if(curr>top && curr>bottom){
                return {mid,col};
            }

            else if(curr<bottom){
                l=mid+1;
            }

            else{
                r=mid-1;
            }
        }

        return {-1,-1};
    }
};