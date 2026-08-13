class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string st="123456789";
        vector<int> ans;
        string L=to_string(low);
        string H=to_string(high);
        int l=L.size();
        int h=H.size();

        for(int i=l; i<=h; i++){
            for(int j=0; j<9-i+1; j++){
                int n=stoi(st.substr(j,i));
                if(n<=high && n>=low){
                    ans.push_back(n);
                }
            }
        }

        return ans;
    }
};