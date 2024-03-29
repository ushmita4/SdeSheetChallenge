

#include<queue>

class Kthlargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;

    Kthlargest(int k, vector<int> &arr) {
        size = k;
        for (auto it:arr) {
            pq.push(it);
            if (pq.size() > size) {

               
                pq.pop();             
            }
        }
    }

    void add(int num) {
        pq.push(num);
        if (pq.size() > size) {
            pq.pop();
        }

    }

    int getKthLargest() {

       
        return pq.top();     
    }

};
