class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*std::min_element(nums.begin(), nums.end()), *std::max_element(nums.begin(), nums.end()));
    }
};