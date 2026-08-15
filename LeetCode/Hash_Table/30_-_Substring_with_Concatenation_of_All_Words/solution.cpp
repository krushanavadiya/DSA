class Solution {
public:
    bool checkSubstring(unordered_map<string, int> fq, string s, int m) {
        for(int j=0; j<s.size(); j+=m) {
            string w=s.substr(j, m);
            if(fq.find(w)!=fq.end()) {
                if(--fq[w]==-1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m=words[0].size();
        int n=s.size();
        int len=words.size() * m;
        
        unordered_map<string, int> fq;
        for(int i=0; i<words.size(); i++) {
            fq[words[i]]++;
        }
        
        int i=0;
        while(i+len<=n) {
            if(checkSubstring(fq, s.substr(i, len), m)) {
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};