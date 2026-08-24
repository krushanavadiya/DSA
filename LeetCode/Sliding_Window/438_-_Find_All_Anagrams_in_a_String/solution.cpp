class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();

        unordered_map<char, int> fq;
        for(int i=0; i<m; i++){
            fq[p[i]]++;
        }

        int j=0;
        vector<int> ans;
        int count=0;

        for(int i=0; i<n; i++){
            if(fq.find(s[i])!=fq.end()){
                fq[s[i]]--;
                if(fq[s[i]]>=0){
                    count++;
                }
            }

            if(i-j+1>m){
                //to restore the deleted elements to check the elements for further window
                if(fq.find(s[j])!=fq.end()){
                    fq[s[j]]++;
                    if(fq[s[j]]>0){
                        count--;
                    }
                }
                j++;
            }

            if(count==m) ans.push_back(j);
        }

        return ans;
    }
};