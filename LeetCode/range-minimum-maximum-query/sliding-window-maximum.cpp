class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0, r=0;
        map<int, int> mp;
        vector<int> ans;

        while(l<=r && r<n){
            mp[nums[r]]++;

            if(r-l+1>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            if(r-l+1==k){
                int swmax=mp.rbegin()->first;
                ans.push_back(swmax);
            }
            r++;
        }

        return ans;
    }
};