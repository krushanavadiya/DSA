class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string , vector<string>> fq;

        for(int i=0; i<n; i++){
            string st=strs[i];
            sort(st.begin(), st.end());
            fq[st].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it: fq){
            ans.push_back(it.second);
        }

        return ans;
    }
};

