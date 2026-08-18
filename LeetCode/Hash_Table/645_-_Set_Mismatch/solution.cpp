class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }

        int dup=-1, missing=-1;

        for(int i=1; i<=n; i++){
            if(fq[i]==2) dup=i;
            else if(fq[i]==0) missing=i;
        }

        return {dup, missing};
    }
};