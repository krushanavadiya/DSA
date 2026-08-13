class Solution {
public:
    int monkeyMove(int n) {
        long MOD = 1000000007;
        long N = n;
        long x = 2;     
        long res = 1;    

        while (N > 0) {
            if (N % 2 == 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            N /= 2;
        }

        // apply formula: 2^n - 2
        return (int)((res - 2 + MOD) % MOD);


    }
};