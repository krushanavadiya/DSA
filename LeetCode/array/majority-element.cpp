class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // unordered_map<int,int> freq;

        // for(int i=0; i<n; i++){
        //     freq[nums[i]]++;
        // }
        
        // for(int i=0; i<n; i++){
        //     if(freq[nums[i]]>n/2){
        //         return nums[i];
        //     }
        // }

        // return -1;

        sort(nums.begin(),nums.end());
            // int count=1;
            // for(int i=1; i<n; i++){    
            //     if(nums[i-1]==nums[i]){
            //         count++;
            //         if(count>n/2){
            //             return nums[i];
            //         }
            //     }
            //     else{
            //         count=1;
            //     }
            // }
            // return -1;

            //or we can simply this do this
            return nums[n/2];
    }
};