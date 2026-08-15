class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        else if(n<10) return false;
        else{
            int sum=0;
            while(n>0){
                int num=n%10;
                sum+= num*num;
                n=n/10;
            }
            return isHappy(sum);
        }
    }
};

