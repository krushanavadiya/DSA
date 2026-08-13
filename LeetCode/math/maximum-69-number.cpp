class Solution {
public:
    int maximum69Number (int num) {
        int Max=INT_MIN;
        string txt= to_string(num);

        for(int i=0; i<txt.size(); i++){
            if(txt[i]=='6'){
                txt[i]='9';
                break;
            }
        }

        return stoi(txt);
    }
};