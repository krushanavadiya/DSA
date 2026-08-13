class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n == 0) return 0;

    vector<int> dp(n + 1, 0);
    
    if (n >= 1) dp[1] = 1 + costs[0];

    for (int i = 2; i <= n; i++) {
        int min_prev = INT_MAX;

        if (i - 1 >= 0) min_prev = min(min_prev, dp[i - 1] + 1);
        if (i - 2 >= 0) min_prev = min(min_prev, dp[i - 2] + 4);
        if (i - 3 >= 0) min_prev = min(min_prev, dp[i - 3] + 9);

        dp[i] = min_prev + costs[i - 1];
    }

    return dp[n];
    }
};