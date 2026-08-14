    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0, j=0;

        unordered_map<char, int> fq;
        int len=0;

        while(i<n){
            fq[s[i]]++;
            for(auto it: fq){
                if(it.second>2){
                    fq[s[j]]--;
                    j++;
                }
            }
            len=max(len, i-j+1);
            i++;
        }

        return len;
    }
};

