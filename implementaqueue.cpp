class Queue {
public:
    int qfront, rear, size, queueSize;
    int q[100010];
    Queue() {

        
        rear = 0;
        qfront = 0;
        size = 0;
        queueSize = 100010;

    }

    
    bool isEmpty() {
        if (qfront == rear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {

        q[rear] = data;
        rear = rear + 1;

        
        size++;
    }

    int dequeue() {

        
        if (isEmpty()) {
            return -1;
        }

        int ans = q[qfront];
        qfront++;
        size--;
        if (qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {

        if (isEmpty()) {
            return -1;
        }

      
        return q[qfront];
    }
};
