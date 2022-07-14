


int left(int k) {
    return 2 * k + 1;
}


int right(int k) {
    return 2 * k + 2;
}


int parent(int k) {
    return (k - 1) / 2;
}


int heapify(vector < int > & heap, int k, int & size) {


    int l = left(k);


    int r = right(k);


    int smallest = k;

    if (l < size && heap[l] < heap[k]) {
        smallest = l;
    }

    if (r < size && heap[r] < heap[smallest]) {
        smallest = r;
    }

   
    if (smallest != k) {

       
        int tempp = heap[k];
        heap[k] = heap[smallest];
        heap[smallest] = tempp;

       
        heapify(heap, smallest, size);
    }
}


void insert(vector < int > & heap, int val, int & size) {

   
    heap[size] = val;

   
    int i = size;

    size += 1;

    while (i != 0 && heap[parent(i)] > heap[i]) {

       
        swap(heap[i], heap[parent(i)]);

      
        i = parent(i);
    }
}

int extractMin(vector < int > & heap, int & size) {

  
    if (size == 1) {
        size -= 1;
        return heap[0];
    }

    
    int val = heap[0];


    heap[0] = heap[size - 1];

    
    size -= 1;

   
    heapify(heap, 0, size);

    return val;
}


vector < int > minHeap(int n, vector < vector < int >> & q) {

    int size = 0;

    vector < int > heap(n);

  
    vector < int > ans;

    for (int i = 0; i < n; i++) {

       
        if (q[i][0] == 0) {
            insert(heap, q[i][1], size);
        } else {
            ans.push_back(extractMin(heap, size));
        }
    }

   
    return ans;
}
