class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        unordered_map<int, int> fq;

        stack<int> st;
        int i=n2-1;

        while(i>=0){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                fq[nums2[i]]=st.top();
            }
            else{
                fq[nums2[i]]=-1;
            }
            st.push(nums2[i]);
            i--;
        }

        vector<int> ans(n1);
        for(int i=0; i<n1; i++){
            ans[i]=fq[nums1[i]];
        }
        
        return ans;
    }
};