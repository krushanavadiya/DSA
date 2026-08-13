class Solution {
    public void reverseString(char[] s) {
        int n=s.length;
        int i=0;
        int j=n-1;

        while(i<j){
            s[i]=(char)(s[i]+s[j]);
            s[j]=(char)(s[i]-s[j]);
            s[i]=(char)(s[i]-s[j]);
            i++;
            j--;
        }
    }
}