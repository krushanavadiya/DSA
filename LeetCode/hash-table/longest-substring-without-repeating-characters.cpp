class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;

        for(int i=0; i<s.size(); i++){
            vector<bool> vis(256,false);

            for(int j=i; j<s.size(); j++){

                if(vis[s[j]]==true){
                    break;
                }

                else{
                    ans=max(ans,j-i+1);
                    vis[s[j]]=true;
                }
            }
        }
        return ans;
    }
};