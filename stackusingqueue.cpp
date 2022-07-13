#include <queue>

class Stack {
   public:
    queue<int> *q1;

    
    Stack() {  
        q1 = new queue<int>();
    }

    int getSize() {
       
        return q1->size();  
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(int data) {
       
        int size = q1->size();  
      
        q1->push(data);         

        for (int i = 0; i < size; i++)  
        {
            q1->push(q1->front());
            q1->pop();
        }
    }

    int pop() {
        
        if (isEmpty()) {  
            return -1;
        }

      
        int ans = q1->front();  
        q1->pop();
        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        int ans = q1->front();

        return ans;
    }
};
