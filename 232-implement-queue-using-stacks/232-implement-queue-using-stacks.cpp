class MyQueue {
public:
    stack<int> st;
    
    MyQueue() {
            
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> st1;
        while(!st.empty()) {
            int val = st.top();
            st1.push(val);
            st.pop();
        }

        int val = st1.top();
        st1.pop();
                
        while(!st1.empty()) {
            int val = st1.top();
            st.push(val);
            st1.pop();
        }
        
        return val;
    }
    
    int peek() {
        stack<int> st1;
        while(!st.empty()) {
            int val = st.top();
            st1.push(val);
            st.pop();
        }

        int val = st1.top();
                
        while(!st1.empty()) {
            int val = st1.top();
            st.push(val);
            st1.pop();
        }
        
        return val;
    }
    
    bool empty() {
        return st.empty();
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