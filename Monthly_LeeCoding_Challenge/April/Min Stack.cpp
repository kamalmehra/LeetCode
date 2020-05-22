
class MinStack {
public:
    /** initialize your data structure here. */
    vector<long long> st;
    int size;
    long long min;
        
    MinStack() {
        min = 4147483647;
        size = -1;
    }
    
    void push(int x) {
        st.push_back(x);
        if(x<min)
            min = x;
        size++;
    }
    
    void pop() {
        if(size>=0){
            st.pop_back();
            size--;
            min = 4147483647;
            for(int i = 0; i<=size; i++){
                if(st[i]<=min)
                    min=st[i];
            }
        }
        else{
            min = 4147483647;
        }
            
    }
    
    int top() {
        return st[size];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */