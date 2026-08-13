class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(), nums.end());

        // for(int i=0; i<n-1; i++){
        //     if(nums[i]==nums[i+1]-1){
        //         continue;
        //     }
        //     else{
        //         return nums[i]+1;
        //     }
        // }

        // if(nums[0]==0){
        //     return nums[n-1]+1;
        // }
        // else{
        //     return nums[0]-1;
        // }


        int sum=n*(n+1)/2;

        for(int i=0; i<n; i++){
            sum-=nums[i];
        }

        return sum;


    }
};