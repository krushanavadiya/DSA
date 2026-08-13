class Solution {
public:
    // int gcd(int a, int b) {
    //     while (b != 0) {
    //         int temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;
    // }

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;;
        vector<int> prefix(n);

        for(int i=0; i<n; i++){
            mx=max(mx, nums[i]);
            prefix[i]=std::gcd(nums[i], mx);
        }

        long long sum=0;

        sort(prefix.begin(), prefix.end());

        int i=0, j=n-1;

        while(i<j){
            sum+=std::gcd(prefix[i], prefix[j]);
            i++; 
            j--;
        }

        return sum;
    }
};