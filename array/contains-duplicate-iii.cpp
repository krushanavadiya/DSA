class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<int> a=nums;
        int n = a.size();
        set<int> s;
        for(int i = 0; i<n; i++){
            
            if( i > indexDiff ){
                // erase the last elemet from set
                s.erase(a[i-indexDiff-1]);
            }
            auto pt = s.lower_bound(a[i]-valueDiff);
            if(pt!=s.end() && abs((*pt)-a[i]) <= valueDiff){
                return true;
            }

            s.insert(a[i]);
        }

        return false;

    }
};