class Solution {
public:
    int maxOperations(string s) {
        int i=0;
        int count=0;
        int count_1=0;

        if(s.size()==0){
            return 0;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                count_1++;
            }

            else if (i > 0 && s[i-1] == '1') {
                count+=count_1;
            }
        }
        return count;
    }
};