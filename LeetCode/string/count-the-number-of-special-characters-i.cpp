class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int count=0;

        unordered_map<char, int> spl;
        unordered_map<char, int> spu;

        for(auto ch: word)
        {
           if(islower(ch)){
            spl[ch]=ch-'a' ;
           }
           if(isupper(ch)){
                spu[ch]= ch -'A';
            }
        }

        for(auto ch : spl){
            char lch= ch.first;
            char uch= toupper(lch);

            if(spu.contains(uch)){
                count++;
            }
        }

        return count;
    }
};