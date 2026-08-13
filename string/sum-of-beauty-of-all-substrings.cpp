class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int count=0;
        
        for(int i=0; i<n; i++){
            unordered_map<char, int> fq;
            for(int j=i; j<n; j++){
                fq[s[j]]++;

                if(fq.size()>=1){
                    int fqmin=INT_MAX;
                    int fqmax=0;
                    for(auto it: fq){
                        fqmin=min(fqmin, it.second);
                        fqmax=max(fqmax, it.second);
                    }

                    count+=fqmax-fqmin;
                }
            }
        }

        return count;
    }
};