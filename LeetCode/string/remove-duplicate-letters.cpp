class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        
        unordered_map<char ,int> fq; //last seen
        unordered_set<char> vis;
        stack<int> st;

        for(int i=0; i<n; i++){
            fq[s[i]]=i;
        }

        for(int i=0; i<n; i++){
            char c=s[i];

            if(!vis.count(c)){
                while(!st.empty() && c<st.top() && i<fq[st.top()]){
                    vis.erase(st.top());
                    st.pop();
                }
                vis.insert(c);
                st.push(c);
            }

        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};