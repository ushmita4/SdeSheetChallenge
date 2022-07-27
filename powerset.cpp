void solve(int idx, vector<int> &arr, vector<int> curr, vector<vector<int>> &ans) 
{
   
    if (idx >= arr.size()) 
    {
        ans.push_back(curr);
        return;
    }
    
    
    solve(idx + 1, arr, curr, ans);

    
    curr.push_back(arr[idx]);
    solve(idx + 1, arr, curr, ans);
}

vector<vector<int>> pwset(vector<int> arr) 
{
 
    vector<vector<int>> ans;
    
    vector <int> curr;
    int idx = 0;

    solve(idx, arr, curr, ans);

    
    return ans;
}
