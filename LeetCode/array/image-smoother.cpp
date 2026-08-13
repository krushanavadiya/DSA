class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));

        for(int i=0; i<img.size(); i++){
            for(int j=0; j<img[0].size(); j++){
                int sum=0;
                int count=0;
                sum+=img[i][j];
                count++;
                    if(i>0 && j>0 ){
                        sum+=img[i-1][j-1];
                        count++;
                    }
                    
                    if(i>0 && j>=0){
                        sum+=img[i-1][j];
                        count++;
                    }
                    
                    if(i>0 && j<m-1){
                        sum+=img[i-1][j+1];
                        count++;
                    }
                    
                    if(i>=0 && j>0){
                        sum+=img[i][j-1];
                        count++;
                    }
                    
                    if(i>=0 && j<m-1){
                        sum+=img[i][j+1];
                        count++;
                    }
                    
                    if(i<n-1 && j>0){
                        sum+=img[i+1][j-1];
                        count++;
                    }
                    
                    if(i<n-1 && j>=0){
                        sum+=img[i+1][j];
                        count++;
                    }
                    
                    if(i<n-1 && j<m-1){
                        sum+=img[i+1][j+1];
                        count++;
                    }

                int avg=sum/count;
                ans[i][j]=avg;    
            }
        }

        return ans;
    }
};