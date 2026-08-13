class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dup=matrix;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dup[i][j]==0){
                    for(int k=0; k<n; k++){
                        matrix[k][j]=0;
                    }
                    for(int l=0; l<m; l++){
                        matrix[i][l]=0;
                    }
                }
            }
        }

    }
};