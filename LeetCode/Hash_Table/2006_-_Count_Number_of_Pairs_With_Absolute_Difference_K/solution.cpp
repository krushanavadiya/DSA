class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> fq;
        int n=nums.size();
        int c=0;

        for(int i=0; i<n; i++){
            c+=fq[nums[i]+k];
            c+=fq[nums[i]-k];
            fq[nums[i]]++;
        }


        return c;
    }
};