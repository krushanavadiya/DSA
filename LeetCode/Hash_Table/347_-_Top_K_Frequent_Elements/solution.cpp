class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int, int> fq;
        vector<int> ans;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }

        priority_queue <pair<int, int>> pq;

        for(auto it: fq){
            pq.push({it.second, it.first});
        }

        while(k>0){
            auto [x, y]=pq.top();
            ans.push_back(y);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};