class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        int i=0;
        int ans=0;
        stack<int> st;

        while(i<n){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int x=st.top();
                x=x*2;
                st.push(x);
            }
            else if(operations[i]=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                int sum=x+y;
                st.push(sum);
            }
            else{
                st.push(stoi(operations[i]));
            }
            i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
        
    }
};