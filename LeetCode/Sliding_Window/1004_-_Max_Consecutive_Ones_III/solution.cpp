class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int, int> fq;
        int j=0;
        int len=0;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;

            while(fq[0]>k){
                fq[nums[j]]--;
                j++;
            }

            len=max(len, i-j+1);
        }

        return len;
    }
};