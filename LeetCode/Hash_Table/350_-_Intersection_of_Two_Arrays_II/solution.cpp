class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        unordered_map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[nums1[i]]++;
        }

        vector<int> ans;

        for(int i=0; i<m; i++){
            if(fq[nums2[i]]>0){
                ans.push_back(nums2[i]);
                fq[nums2[i]]--;
            }
        }

        return ans;
    }
};

