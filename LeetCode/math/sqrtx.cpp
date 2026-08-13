class Solution {
public:
    int mySqrt(int x) {
        long long ans=0;

        if(x<=0){
            return 0;
        }

        long long left=0;
        long long right=x;

        while(left<=right){
            long long mid=(left+right)/2;

            if(mid*mid==x){
                return mid;
            }

            if(mid*mid<x){
                left=mid+1;
            }

            else{
                right=mid-1;
            }

        }
        
        return right;
    }
};