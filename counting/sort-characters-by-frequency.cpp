class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char, int> fq;
        string ans="";

        for(int i=0; i<n; i++){
            fq[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto i: fq){
            int c= i.second;
            char ch=i.first;

            pq.push({c,ch});
        }

        while(!pq.empty()){
            auto i=pq.top();
            int c= i.first;
            char ch=i.second;
            
            ans.append(c,ch);
            pq.pop();
        }

        return ans;
        
    }
};