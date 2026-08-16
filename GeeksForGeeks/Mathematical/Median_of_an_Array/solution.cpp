class Solution {
  public:
    double findMedian(vector<int> &arr) {
        // code here.
        int n=arr.size();
        sort(arr.begin(), arr.end());
        
        return n%2==0 ? (arr[n/2]+arr[(n/2)-1])/2.0 : arr[n/2];
    }
};
