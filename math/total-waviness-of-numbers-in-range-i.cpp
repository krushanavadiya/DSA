class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count=0;

        if(num1<100 && num2<100) return 0;

            for(int i=num1; i<=num2; i++){
                string st=std::to_string(i);
                int l=st.size();

                for(int i=1; i<l-1; i++){
                    if(st[i]>st[i-1] && st[i]>st[i+1] || st[i]<st[i-1] && st[i]<st[i+1]){
                        count++;
                    }
                }
            }

        return count;
    }
};