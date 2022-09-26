class MinStack {
public:
    stack<int> st, s2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        // before pushing in min stack(s2) check whether the s2 is empty or val <= s2.top.
        if(s2.empty() or val <= s2.top()){
            s2.push(val);
        }    
        // we have to push in stack every time
        st.push(val);
    }
    
    void pop() {
        // before poping from min stack check whether top of both stack is same or not if same remove from both stacks.
        if(st.top() == s2.top()){
            s2.pop();
        }
        // we have to pop from main stack every time pop function is called
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */