class Solution {
public:
    bool checkValidString(string s) {
        // return solve(s, 0, 0);
        int n=s.size();
        int minopn=0;
        int maxopn=0;

        for(int i=0; i<n; i++){
            if(s[i]==')'){
                minopn--;
                maxopn--;
            }
            else if(s[i]=='('){
                maxopn++;
                minopn++;
            }
            else{
                minopn--;
                maxopn++;
            }
            if(minopn<0) minopn=0;
            if(maxopn<0) return false;
        }

        if(minopn==0){
            return true;
        }
        else{
            return false;
        }
    }

    // bool solve(string s, int i, int count){
    //     if(count<0){
    //         return false;
    //     }

    //     if(i==s.size()){
    //         if(count==0){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }

    //     if(s[i]=='('){
    //         return solve(s, i+1, count+1);
    //     }
    //     else if(s[i]==')'){
    //         return solve(s, i+1, count-1);
    //     }
    //     else{
    //         bool open=solve(s, i+1, count+1);
    //         bool close=solve(s, i+1, count-1);
    //         bool empty=solve(s, i+1, count);

    //         if(open==true || close==true || empty==true){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    // }
};