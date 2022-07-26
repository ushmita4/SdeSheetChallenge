

void subset(int i, int sum, vector<int> &num, vector<int> &ans)
{

    
    if (i == num.size())
    {
        ans.push_back(sum);
        return;
    }

    subset(i + 1, sum + num[i], num, ans);
  
    subset(i + 1, sum, num, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    
    vector<int> ans;

    subset(0, 0, num, ans);
    
    sort(ans.begin(), ans.end());
    return ans;
}
