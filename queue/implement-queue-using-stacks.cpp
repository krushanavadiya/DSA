class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st2.push(x);
        stack<int> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        swap(st, st2);
        return;
    }
    
    int pop() {
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return (st.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */