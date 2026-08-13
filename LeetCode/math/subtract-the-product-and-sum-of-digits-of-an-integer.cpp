class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int i=0,j;
        int A[100];
        int product=1;
        int sum=0;
        while(n>0){
            int a=n%10;
            A[i]=a;
            i++;
            n=n/10;
        }
       for(j=0;j<i;j++){
        
        product *= A[j];
        
        sum += A[j];
       }
        int result=product-sum;
        return result;
        
    }
};