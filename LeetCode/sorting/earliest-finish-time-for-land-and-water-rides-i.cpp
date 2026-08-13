class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ls=landStartTime.size();
        int ld=landDuration.size();

        int ws=waterStartTime.size();
        int wd=waterDuration.size();

        int ans=INT_MAX;

        for(int i=0; i<ls; i++){
            for(int j=0; j<ws; j++){
                int land=landStartTime[i]+landDuration[i];
                int water=max(land,waterStartTime[j]);
                int t=water+waterDuration[j];
                ans=min(ans,t);
            }
        }

        for(int i=0; i<ws; i++){
            for(int j=0; j<ls; j++){
                int water=waterStartTime[i]+waterDuration[i];
                int land=max(water,landStartTime[j]);
                int t=land+landDuration[j];
                ans=min(ans,t);
            }
        }

        return ans;
    }
};