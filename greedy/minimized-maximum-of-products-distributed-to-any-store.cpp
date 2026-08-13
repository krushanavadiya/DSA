class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1;
        int r=*std::max_element(quantities.begin(), quantities.end());

        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            int shops=0;
            for(int i=0; i<m; i++){
                shops+=quantities[i]/mid;
                if(quantities[i]%mid!=0){
                    shops++;
                }
            }

            if(shops<=n){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};