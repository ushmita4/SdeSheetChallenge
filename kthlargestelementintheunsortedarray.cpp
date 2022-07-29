

int kthLargest(vector<int>& arr, int size, int K)
{
    
    priority_queue<int, vector<int>, greater<int> >pq;
    int val;
    for (int i = 0; i < size; i++)
    {
        if (i < K)
        {
            pq.push(arr[i]);
        }

        else
        {
            val = pq.top();
            if (val < arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }

        }

    }

    return pq.top();
}
