
#include <stack>

class Queue {
    stack<int> *st;
public:
    Queue() {
        
        st = new stack<int>();     
    }

    void enQueue(int val) {
        
        st->push(val);
    }

    
    int deQueue() {
    
        if (st->empty()) {
            return -1;
        }

    
        int x = st->top();
        st->pop();     

                 
        if (st->empty()) {
            return x;                  
        }

       
        int nxt = deQueue();      
        
        st->push(x);              
        return nxt;
    }

  
    int peek() {
        if (st->empty()) {
            return -1;
        }

        int x = st->top();
        st->pop();
        if (st->empty()) {
            st->push(x);
            return x;
        }

        int nxt = peek();
        st->push(x);
        return nxt;
    }

  
    bool isEmpty() {
        return (st->empty());
    }
};
