class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> net(n+1);
        net[0]=0;

        for(int i=1; i<=n; i++){
            net[i]=gain[i-1]+net[i-1];
        }

        return *std::max_element(net.begin(), net.end());

    }
};