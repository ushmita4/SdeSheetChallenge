
int upper_bound(vector<int> const &arr, int first, int last, int val)
{
    
    int low = first, high = last;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > val)
        {
            
            high = mid;
        }
        else
        {
            
            low = mid + 1;
        }
    }

    return low;
}

int getMedian(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

  
    int low = 1, high = 100000;

    
    while (low < high)
    {

        int mid = (low + high) / 2;

        
        int count = 0;

       
        for (int i = 0; i < n; i++)
        {
           
            count = count + upper_bound(matrix[i], 0, matrix[i].size(), mid);
        }

        if (count >= (n * m + 1) / 2)
        {
     
            high = mid;
        }
        else
        {
    
            low = mid + 1;
        }
    }
    return low;
}
