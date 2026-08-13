class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> a(n*m);

        for(int i=0; i<n*m; i++){
            a[i]=matrix[i/m][i%m];
        }

        sort(a.begin(), a.end());

        int l=0;
        int r=(n*m)-1;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(mid<=k-1){
                ans=a[mid];
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return ans;
    }
};