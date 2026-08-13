    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> fq;
        int n=nums.size();

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }

        vector<int> ans;

        for(auto it: fq){
            int i=it.second;
            if(i>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }

