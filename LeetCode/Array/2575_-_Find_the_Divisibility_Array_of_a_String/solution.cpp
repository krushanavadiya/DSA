class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        long long int num=0;
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            num=num*10+(word[i]-'0');
            if(num%m==0){
                ans[i]=1;
            }
            else{
                ans[i]=0;
            }
            num=num%m;
        }

        return ans;
    }
};