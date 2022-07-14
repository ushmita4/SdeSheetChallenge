

#include <climits>


bool isCommon(vector<string> &arr, string &prefix, int length, int n)
{
    for(int idx = 0; idx < length; ++idx)
    {
        for(int index = 0; index < n; index++)
        {
            
            if (arr[index][idx] != prefix[idx])
            {
                return false;
            }
        }
    }
    
   
    return true; 
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    
    string prefix = "";

  
    int minLength = INT_MAX;

    for(int index = 0;index < n; ++index)
    {
        if (arr[index].size() < minLength)
        {
            minLength = arr[index].size();
            prefix = arr[index];
        }
    }

    int start = 0;
    int end = minLength;
    int mid;

    while (start <= end)
    {   
        mid = (start + end) / 2;

        
        if (isCommon(arr, prefix, mid, n))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    mid = (start + end) / 2;

    
    string answer = prefix.substr(0, mid);

    return answer;
}




