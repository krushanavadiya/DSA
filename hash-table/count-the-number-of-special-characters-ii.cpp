class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        unordered_map<char, int> occU;
        unordered_map<char, int> occL;
        int count=0;

        for(int i=0; i<n; i++){
            if(occU.contains(word[i])==false && isupper(word[i])){
                occU[word[i]]=i;
            }
            else if(islower(word[i])){
                occL[word[i]]=i;
            }
        }

        for(auto pair: occL){
            char lch= pair.first;
            char uch= toupper(lch);

            int Locc=pair.second;

            if(occU.contains(uch) && occU[uch]>Locc){
                count++;
            }
        }

        return count;
    }
};