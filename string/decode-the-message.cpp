class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> fq;
        int j=0;
        for(int i=0; i<key.size(); i++){
            if(key[i]!=' ' && !fq.contains(key[i])){
                fq[key[i]]=(char)('a'+j);
                j++;
            }
        }

        string ans="";
        for(int i=0; i<message.size(); i++){
            if(message[i]==' '){
                ans+=" ";
            }
            else{
                ans+=fq[message[i]];
            }
        }

        return ans;
    }
};