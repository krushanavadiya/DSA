class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        if(lower<nums[0]){
            int num=min(nums[0]-1, upper);
            if(lower<=num) ans.push_back({lower, num});
        }

        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]+1){
                int st=max(lower, nums[i-1]+1);
                int end=min(upper, nums[i]-1);

                if(st<=end){
                    ans.push_back({st, end});
                }
            }
        }

        if(upper>nums[n-1]){
            int num=max(lower, nums[n-1]+1);
            if(num<=upper) ans.push_back({num, upper});
        }

        return ans;
    }
};