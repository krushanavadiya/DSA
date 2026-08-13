class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n=words.size();
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        
        vector<string> ans;

        for(int i=0; i<n; i++){
            string s=words[i];
            unordered_map<char,int> freq;
            for(int j=0; j<s.size(); j++){
                char c=tolower(s[j]);
                freq[c]++;
            }
            
            char f=tolower(s[0]);
            bool isvalid=true;

            if(f=='q' || f=='w' || f=='e' || f=='r'|| f=='t' || f=='y'||f=='u' || f=='i'||f=='o' || f=='p'){
                for(auto it:freq){
                    auto r=it.first;
                    if(r=='q' || r=='w' || r=='e' || r=='r'|| r=='t' || r=='y'||r=='u' || r=='i'||r=='o' || r=='p'){
                        continue;
                    }
                    else{
                        isvalid=false;
                        break;
                    }
                }
                if(isvalid){
                    ans.push_back(s);
                }
                
            }
            else if(f=='a' || f=='s' || f=='d' || f=='f'|| f=='g' || f=='h'||f=='j' || f=='k'||f=='l'){
                for(auto it:freq){
                    auto r=it.first;
                    if(r=='a' || r=='s' || r=='d' || r=='f'|| r=='g' || r=='h'||r=='j' || r=='k'||r=='l'){
                        continue;
                    }
                    else{
                        isvalid=false;
                        break;
                    }
                }
                if(isvalid){
                    ans.push_back(s);
                }
                
            }

            else if(f=='z' || f=='x' || f=='c' || f=='v'|| f=='b' || f=='n'||f=='m'){
                for(auto it:freq){
                    auto r=it.first;
                    if(r=='z' || r=='x' || r=='c' || r=='v'|| r=='b' || r=='n'|| r=='m'){
                        continue;
                    }
                    else{
                        isvalid=false;
                        break;
                    }
                }
                if(isvalid){
                    ans.push_back(s);
                }
            }
        }

        return ans;    
    }
};