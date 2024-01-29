class MyQueue {
    //put the element in q2 
    //push the element to q1
    //push all the element from q2 to q1;
private:
    stack<int> st1, st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       st1.push(x);        
    }
    
    int pop() {
        if(st2.empty())
            while(st1.size())
                st2.push(st1.top()), st1.pop();

        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.empty())
            while(st1.size()) 
                st2.push(st1.top()), st1.pop();
        
        return st2.top();
    }
    
    bool empty() {
        return !(st1.size() | st2.size());
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