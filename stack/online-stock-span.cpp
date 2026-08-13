class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i; //day
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        i++;
        int span=0;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(!st.empty()){
            span=i-st.top().second ;
        }
        else{
            span= i;
        }
        st.push({price, i});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */