class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ls=landStartTime.size();
        int ld=landDuration.size();

        int ws=waterStartTime.size();
        int wd=waterDuration.size();
        
        int ans=INT_MAX;
        int land=INT_MAX;
        int water=INT_MAX;

        for(int i=0; i<ls; i++){
            land=min(land,landStartTime[i]+landDuration[i]);
        }

        for(int i=0; i<ws; i++){
            water=max(land,waterStartTime[i]);
            int t=water+waterDuration[i];               
            ans=min(ans,t);
        }
        
        water=INT_MAX;

        for(int i=0; i<ws; i++){
            water=min(water,waterStartTime[i]+waterDuration[i]);
        }
    
        for(int i=0; i<ls; i++){
            land=max(water,landStartTime[i]);
            int t=land+landDuration[i];
            ans=min(ans,t);
        }
        
        return ans;
    }
};