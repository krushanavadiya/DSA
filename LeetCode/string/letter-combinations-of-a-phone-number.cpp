class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // int n=digits.size();
        // vector<string> ans;
        // unordered_map<char, vector<char>> freq={
        //     {'2',{"'a','b','c'"}}, {'3',{'d','e','f'}}, {'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}
        // };

        // if(n==1){
        //     return freq[digits[0]];
        // }
        // for(int i=0; i<n; i++){
            
        // }

        unordered_map<int,string> m1 = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string> ans;
        int n = digits.size();

        if(n == 1){
            for(auto x : m1[digits[0]-'0']){
                string temp = "";
                temp += x;
                ans.push_back(temp);
            }
        }else if(n == 2){
            for(int i = 0; i<m1[digits[0]-'0'].size(); i++){
                for(int j = 0; j<m1[digits[1]-'0'].size(); j++){
                    string temp = "";
                    temp += m1[digits[0]-'0'][i];
                    temp += m1[digits[1]-'0'][j];
                    ans.push_back(temp);
                }
            }
        }else if(n == 3){
            for(int i = 0; i<m1[digits[0]-'0'].size(); i++){
                for(int j = 0; j<m1[digits[1]-'0'].size(); j++){
                    for(int k = 0; k<m1[digits[2]-'0'].size(); k++){
                        string temp = "";
                        temp += m1[digits[0]-'0'][i];
                        temp += m1[digits[1]-'0'][j];
                        temp += m1[digits[2]-'0'][k];
                        ans.push_back(temp);
                    }
                }
            }
        }else{
            for(int i = 0; i<m1[digits[0]-'0'].size(); i++){
                for(int j = 0; j<m1[digits[1]-'0'].size(); j++){
                    for(int k = 0; k<m1[digits[2]-'0'].size(); k++){
                        for(int l = 0; l<m1[digits[3]-'0'].size(); l++){
                            string temp = "";
                            temp += m1[digits[0]-'0'][i];
                            temp += m1[digits[1]-'0'][j];
                            temp += m1[digits[2]-'0'][k];
                            temp += m1[digits[3]-'0'][l];
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};