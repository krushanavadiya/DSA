class Solution {
public:
        const int M = 1e9+7;
    int binpow(long long a, long long b){ if (b == 0){return 1;}long long ans = binpow(a, b / 2);ans *= ans;ans %= M;if (b % 2){ans *= a;}return ans%M;}

    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        long long count = 0;
        long long i = 0;
        long long j = n-1;
        while(i < n && i <= j){

            while(i <= j && (nums[i] + nums[j] > target)){
                j--;
            }
            if (j < i) break;
            count = (count%M + binpow(2,j-i))%M;
            i++;
        }

        return count;

    }
};
