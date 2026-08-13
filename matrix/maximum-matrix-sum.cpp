class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int Min=INT_MAX;
        int count=0;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    count++;
                }

                Min=min(Min,abs(matrix[i][j]));
            }
        }

        if(count%2!=0){
            sum=sum-(2*Min);
        }

        return sum;

    }
};