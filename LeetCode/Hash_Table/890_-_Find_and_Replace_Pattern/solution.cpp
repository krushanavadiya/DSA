class Solution {
public:
    bool isIsomorphic(string word, string pattern){
        unordered_map<char, char> fq;
        unordered_map<char, char> fq1;

            for(int j=0; j<word.size(); j++){
                char w=word[j];
                char t=pattern[j];

                if(fq.contains(w) && fq[w]!=t) return false;
                if(fq1.contains(t) && fq1[t]!=w) return false;

                fq[w]=t;
                fq1[t]=w;
            }

            return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words.size();
        int m=words[0].size();
        int l=pattern.size();

        if(m!=l) return{};
        vector<string> ans;

        for(int i=0; i<n; i++){
            string word=words[i];
            if(isIsomorphic(word, pattern)){
                ans.push_back(word);
            }
        } 

        return ans;
    }
};