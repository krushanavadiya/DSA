class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,j=0;
        while(i<n){
            char c=chars[i];
            int count=0;

            while(i<n && chars[i]==c){
                count++;
                i++;
            }

            chars[j]=c;
            j++;

            if(count>1){
                for(char ch:to_string(count)){
                    chars[j]=ch;
                    j++;
                }
            }
        }

        return j;
    }
};