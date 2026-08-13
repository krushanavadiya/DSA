class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(), price.end());
        int l=0;
        int r=price[n-1]-price[0];
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            int candies=1;
            int curr=price[0];

            for(int i=0; i<n; i++){
                int tastiness=abs(curr-price[i]);
                if(tastiness>=mid){
                    candies++;
                    curr=price[i];
                }
            }

            if(candies>=k){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            
        }

        return ans;
    }
};