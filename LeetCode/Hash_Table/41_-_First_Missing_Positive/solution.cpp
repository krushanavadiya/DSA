class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> fq;
        int num=*std::max_element(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]>=0) fq[nums[i]]++;
        }

        for(int i=1; i<num; i++){
            if(!fq.contains(i)){
                return i;
            }
        }

        if(num<0) return 1;
        else return num+1;
    }
};

