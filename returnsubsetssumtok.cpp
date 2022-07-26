

vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
{
   
    vector<vector<int>> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            
            if ((1 << j) & i)
            {
                sum += arr[j];
                vec.push_back(arr[j]);
            }
        }

     
        if (sum == k)
        {
            ans.push_back(vec);
        }
    }

   
    return ans;
}
