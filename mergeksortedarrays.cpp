

vector<int> merge(vector<int>&a, vector<int>&b)
{
    vector<int>ans; 
    
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    
   
    while(i < n and j < m)
    {
        if(a[i] < b[j])
        {
            ans.push_back(a[i]);
            i += 1;
        }
        else
        {
            ans.push_back(b[j]);
            j += 1;
        }
    }
   
    while(i < n)
    {
        ans.push_back(a[i]);
        i += 1;
    }

    while(j < m)
    {
        ans.push_back(b[j]);
        j += 1;
    }
    
    return ans; 
}

vector<int>  mergeKSortedArraysHelper(vector<vector<int>>&kArrays, int start, int end)
{
  
    if(start == end)
    {
        return kArrays[start];
    }
    
  
    if(start + 1 == end)
    {
        return merge(kArrays[start], kArrays[end]);
    }
    
    int mid = start + (end - start)/2;
    
 
    vector<int> first = mergeKSortedArraysHelper(kArrays, start, mid);
    vector<int> second = mergeKSortedArraysHelper(kArrays, mid + 1, end);
    
 
    return merge(first, second);
    
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> result = mergeKSortedArraysHelper(kArrays, 0, k - 1);
    return result;
}
