class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10) return {};
        unordered_map<string, int> fq;
        vector<string> ans;

        for(int i=0; i<=n-10; i++){
            string st=s.substr(i, 10);
            fq[st]++;
        }

        for(auto it: fq){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};