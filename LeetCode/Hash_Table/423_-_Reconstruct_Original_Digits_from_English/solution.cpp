class Solution {
public:
    string originalDigits(string s) {
        int n=s.size();
        unordered_map<char, int> fq;
        string ans="";

        for(int i=0; i<n; i++){
            fq[s[i]]++;
        }
        int i=0;

        while(i<n){
            if(fq['z']>0){
                fq['z']--;
                fq['e']--;
                fq['r']--;
                fq['o']--;

                ans+='0';
                i+=4;
            }
            else if(fq['w']>0){
                fq['t']--;
                fq['w']--;
                fq['o']--;
                ans+='2';
                i+=3;
            }
            else if(fq['u']>0){
                fq['f']--;
                fq['o']--;
                fq['u']--;
                fq['r']--;

                ans+='4';
                i+=4;
            }
            else if(fq['x']>0){
                fq['s']--;
                fq['i']--;
                fq['x']--;

                ans+='6';
                i+=3;
            }
            else if(fq['g']>0){
                fq['e']--;
                fq['i']--;
                fq['g']--;
                fq['h']--;
                fq['t']--;

                ans+='8';
                i+=5;
            }
            else if(fq['o']>0 && fq['n']>0 && fq['e']>0){
                fq['o']--;
                fq['n']--;
                fq['e']--;

                i+=3;
                ans+='1';
            }
            
            else if(fq['t']>0 && fq['h']>0 && fq['r']>0 && fq['e']>=2){
                    fq['t']--;
                    fq['h']--;
                    fq['r']--;
                    fq['e']-=2;

                    ans+='3';
                    i+=5;
            }
            
            else if(fq['f']>0 && fq['i']>0 && fq['v']>0 && fq['e']>0){
                fq['f']--;
                fq['i']--;
                fq['v']--;
                fq['e']--;

                ans+='5';
                i+=4;
            }
            
            else if(fq['v']>0 && fq['e']>=2 && fq['s']>0 && fq['n']>0){
                    fq['s']--;
                    fq['e']-=2;
                    fq['v']--;
                    fq['n']--;

                    ans+='7';
                    i+=5;
                
            }
            
            else if(fq['n']>=2 && fq['i']>0 && fq['e']>0){
                    fq['n']-=2;
                    fq['i']--;
                    fq['e']--;

                    ans+='9';
                    i+=4;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};