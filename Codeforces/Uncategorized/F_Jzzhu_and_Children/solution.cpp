#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<int>& child){
    std::queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        q.push({child[i], i});
    }
    
    while(q.size()>1){
        if(q.front().first<=m){
            q.pop();
        }
        else {
            auto curr=q.front();
            int req=curr.first;
            int rem=req-m;
            q.pop();
            q.push({rem, curr.second});
        }
    }
    
    return q.front().second+1;
}

int main() {
	// your code goes here
    int n, m;
    cin>>n>>m;
    
    std::vector<int> child(n);
    for(int i=0; i<n; i++){
        cin>>child[i];
    }
    
    cout<<solve(n, m, child);
}
