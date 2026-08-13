class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;

        sort(restaurants.begin() , restaurants.end() , [](vector<int>& i , vector<int>& j){
            if(i[1] > j[1])return true;
            else if(i[1] == j[1]){
                if(i[0] > j[0]){
                    return true;}

                else {
                return false;}
            }
            else {
                return false;}
        });

        int n = restaurants.size();

        for(int i=0;i<n;i++){
            int m = restaurants[i].size();
            if(veganFriendly == 1 && restaurants[i][2] == 1){
                if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                    ans.push_back(restaurants[i][0]);
                }
            }
            else if(veganFriendly == 0) {
                if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                    ans.push_back(restaurants[i][0]);
                }
            }
        }

        return ans;

    }
};