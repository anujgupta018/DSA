class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        while(st.empty()==false){
            st.pop();
            mini=INT_MAX;
        }
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()){
            mini=val;
            st.push(value);
        }
        else{
            if(value<mini){
                st.push(2* value  - mini);
                mini=val;
            }
            else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        long long el=st.top();
        st.pop();
        if(el<mini){
            mini=mini*2-el;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long el=st.top();
        if(el<mini){
            return mini;
        }
        return el;
    }
    
    int getMin() {
        return mini;
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
