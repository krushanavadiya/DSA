  class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        unordered_map<int, int> fq1;
        unordered_map<int, int> fq2;

        for(int i=0; i<n; i++){
            fq1[nums1[i]]++;
        }

        for(int i=0; i<m; i++){
            fq2[nums2[i]]++;
        }

        vector<int> ans;

        for(auto it: fq1){
            if(fq2.contains(it.first)){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};