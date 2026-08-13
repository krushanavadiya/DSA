class Solution {
public:
    string intToRoman(int num) {
        vector<int> n={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> c={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string st="";

        for(int i=0; i<n.size(); i++){
            while(num>=n[i]){
                num-=n[i];
                st+=c[i];
            }
        }

        return st;
    }
};