class Solution {

public:
    double myPow(double x, long long n) {
        if(x==0) return 0;
        double ans=1.0;
        if(n<0){
            long long N=-n;
            ans=pow(x, N);
            return 1.0/ans;
        }
        if(n>=0){
            ans=pow(x, n);
        }
        
        return ans;
    }

    double pow(double x, long long n){
        if(n==0) return 1;
        
        double half = pow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
        
    