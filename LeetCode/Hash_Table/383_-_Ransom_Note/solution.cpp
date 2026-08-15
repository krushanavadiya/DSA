class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> fq;
        int n=ransomNote.size();
        int m=magazine.size();

        for(int i=0; i<m; i++){
            if(fq.find(magazine[i])==fq.end()){
                fq[magazine[i]]=1;
            }
            else{
                fq[magazine[i]]++;
            }
        }

        for(int i=0; i<n; i++){
            if(fq.find(ransomNote[i])!=fq.end() && fq[ransomNote[i]]>0) fq[ransomNote[i]]--;
            else return false;
        }

        return true;
    }
};