class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> row(n);
        vector<int> col(m);

        for(int i=0; i<n; i++){
            int minr=INT_MAX;
            for(int j=0; j<m; j++){
                minr=min(minr,matrix[i][j]);
            }
            row[i]=minr;
        }

        for(int i=0; i<m; i++){
            int maxc=INT_MIN;
            for(int j=0; j<n; j++){
                maxc=max(maxc,matrix[j][i]);
            }
            col[i]=maxc;
        }

        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i]==col[j]){
                    ans.push_back(row[i]);
                }
            }
        }
        return ans;
    }
};