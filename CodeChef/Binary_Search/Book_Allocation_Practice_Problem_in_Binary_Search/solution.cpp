long long allocateBooks(vector<long long>& books, int N, int M) {
    // complete the logic...
    if(N<M) return -1;
    
    long long l=*std::max_element(books.begin(), books.end());
    long long r=0;
    for(int i=0; i<N; i++){
        r+=books[i];
    }
    
    long long ans=-1;
    
    while(l<=r){
        long long mid=l+(r-l)/2;
        
        long long page=0;
        int st=1;
        
        for(int i=0; i<N; i++){
            if(page+books[i]<=mid){
                page+=books[i];
            }
            else{
                st++;
