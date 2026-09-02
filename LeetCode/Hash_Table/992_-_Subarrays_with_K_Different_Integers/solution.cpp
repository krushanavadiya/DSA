class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        unordered_map<int, int> fq;

        int j=0;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
            while(fq.size()>k){
                fq[nums[j]]--;
                if(fq[nums[j]]==0) fq.erase(nums[j]);
                j++;
            }
            count+=(i-j+1);
        }

        int count1=0;
        j=0;
        unordered_map<int, int> fq1;
        for(int i=0; i<n; i++){
            fq1[nums[i]]++;
            while(fq1.size()>k-1){
                fq1[nums[j]]--;
                if(fq1[nums[j]]==0) fq1.erase(nums[j]);
                j++;
            }
            count1+=(i-j+1);
        }

        return count-count1;
    }
};