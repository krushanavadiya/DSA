class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> fq;
        unordered_map<string, int> bann;
        
        int n=paragraph.size();

        for(int i=0; i<banned.size(); i++){
            bann[banned[i]]++;
        }

        for(int i=0; i<n; i++){
            if(isalpha(paragraph[i])){
                paragraph[i]=tolower(paragraph[i]);
            }
            else{
                paragraph[i]=' ';
            }
        }

        stringstream ss(paragraph);
        string word="";
        string ans="";

        while(ss>>word){
            fq[word]++;
        }

        int count=0;

        for(auto it: fq){
            if(bann.find(it.first)==bann.end()){
                int num=it.second;
                if(count<num){
                    count=num;
                    ans=it.first;
                }
            }
        }

        return ans;
    }
};