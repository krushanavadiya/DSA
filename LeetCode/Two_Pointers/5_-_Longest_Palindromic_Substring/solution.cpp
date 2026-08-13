class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";

        for(int i=0; i<n; i++){
            //for odd length
            int st=i;
            int end=i;

            while(st<n && end>=0 && s[st]==s[end]){
                st++;
                end--;
            }
            string temp=s.substr(end+1, st-end-1);
            if(ans.size()<temp.size()){
                ans=temp;
            }

