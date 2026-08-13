class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        // unordered_map<char,int> freq;

        // for(int i=0; i<n; i++){
        //     freq[word[i]]++;
        // }

        // string ans="";

        // for(int i=0; i<n; i++){
        //     char c=word[i];
        //     if(freq[c]>0){

        //         if(freq[c]<=9){
        //         ans+=to_string(freq[c]);
        //         ans+=c;
        //         }
        //         else{
        //             int r=freq[c]-9;
        //             ans+=to_string(9);
        //             ans+=c;
        //             ans+=to_string(r);
        //             ans+=c;
        //         }
        //     }

        //     freq[c] = 0;
            
        // }

        int i=0;
        string ans="";
        
        while(i<n){
            char c=word[i];
            int count=0;

            while(i<n && count<9 && word[i]==c){
                count++;
                i++;
            }

            ans+=to_string(count);
            ans+=c;
        }
        return ans;
    }
};