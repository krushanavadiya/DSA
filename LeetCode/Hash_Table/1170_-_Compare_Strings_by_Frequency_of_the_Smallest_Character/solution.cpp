class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size();
        int m=words.size();

        unordered_map<int, int>fq;

        for(int i=0; i<m; i++){
            string s=words[i];
            sort(s.begin(), s.end());
            for(int j=0; j<s.size(); j++){
                if(s[j]==s[0]){
                    fq[i]++;
                }
                else{
                    break;
                }
            }
        }

        unordered_map<int, int> fq1;

        for(int i=0; i<n; i++){
            string s=queries[i];
            sort(s.begin(), s.end());
            for(int j=0; j<s.size(); j++){
                if(s[0]==s[j]) fq1[i]++;
                else break;
            }
        }

        vector<int> ans;

        for(int i=0; i<n; i++){
            int count=0;

            for(auto it: fq){
                if(fq1[i]<it.second) count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};