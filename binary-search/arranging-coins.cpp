class Solution {
public:
    int arrangeCoins(int n) {
        long long l=0;
        long long r=n;
        long long ans=0;

        while(l<=r){
            long long m=l+(r-l)/2;

            if( m*(m+1)/2 == n){
                return m;
            }

            else if( m*(m+1)/2 < n){
                ans=m;
                l=m+1;
            }

            else{
                r=m-1;
            }
        }

        return ans;
    }
};