

void merge(vector<int>& arr, int start, int mid, int end)
{
    
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) 
    {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++) 
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    for (int k = start; k <= end; k++) 
    {
        if (j >= n2 || (i < n1 && left[i] <= right[j])) 
        {
            arr[k] = left[i++];
        }

        else 
        {
            arr[k] = right[j++];
        }
    }
}

int mergeSort(vector<int>& arr, int start, int end)
{
    if (start < end) 
    {
        int mid = (start + end) / 2;

        // Counting the pairs in the left and right arrays.
        int count = mergeSort(arr, start, mid) + mergeSort(arr, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) 
        {
            while (j <= end && arr[i] > arr[j] * 2LL) 
            {
                j++;
            }
            count += j - (mid + 1);
        }

        // Merging the arrays.
        merge(arr, start, mid, end);
        return count;
    }
    
    else
    {
        return 0;
    }
}


int reversePairs(vector<int>& arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

