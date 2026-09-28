class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }

        while(!fq.empty()){
            for(auto it: fq){
                ans.push_back(it.first);
                fq[it.first]--;
            }
            erase_if(fq, [](const auto& p){ return p.second==0;});
        }

        return ans;
    }
};