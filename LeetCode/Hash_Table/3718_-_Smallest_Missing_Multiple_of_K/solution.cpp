class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }

        for(int i=k; i<=k*100000; i+=k){
            if(fq.find(i)==fq.end()) return i;
        }

        return -1;
    }
};

