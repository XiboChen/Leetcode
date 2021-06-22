class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q_last.empty()){
            q_last.push(x);
        }else{
            q.push(q_last.front());q_last.pop();
            q_last.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
            int val=top();
            q_last.pop();
            return val;
    }
    
    /** Get the top element. */
    int top() {
        if(q_last.empty()){
            for(int i=0;i<(int)q.size()-1;i++){ 
                q.push(q.front());
                q.pop();
            }
            q_last.push(q.front()); 
            q.pop();
        }
        return q_last.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty()&&q_last.empty();
    }
private:
    queue<int> q;
    queue<int> q_last; //store the last element
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */