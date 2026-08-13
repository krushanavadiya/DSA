class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> fq;
        int n=secret.size();

        for(int i=0; i<n; i++){
            fq[secret[i]]++;
        }

        int c=0, b=0;

        for(int i=0; i<n; i++){
            if(fq[guess[i]]>0){
                c++;
                fq[guess[i]]--;
            }
        }

        for(int i=0; i<n; i++){
            if(secret[i]==guess[i]){
                b++;
                c--;
            }
        }

        return to_string(b)+"A"+to_string(c)+"B";
    }
};