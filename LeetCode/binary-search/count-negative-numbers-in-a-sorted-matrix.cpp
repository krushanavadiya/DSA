class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> arr(n*m);
        for(int i=0; i<n*m; i++){
            arr[i]=grid[i/m][i%m];
        }
        sort(arr.begin(), arr.end());

        int l=0, r=n*m-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(arr[mid]<=-1){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return l;
    }
};