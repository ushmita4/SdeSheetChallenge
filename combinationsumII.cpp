

const int MAX_NUM = 30;  

void backtrack(vector<int> &comb, int remain, int curr, vector<int> &counter, vector<vector<int>> &result) 
{
    if(remain == 0) 
    {
        
        result.push_back(comb);
        return;
    }
    
    if(curr > MAX_NUM) 
    {
        
        return;
    }
        
    while(counter[curr] > 0 && remain >= curr) 
    {
       
        comb.push_back(curr);
        counter[curr]--;
        remain -= curr;
    }
      
    while(comb.size() > 0 && comb.back() == curr) 
    {
        backtrack(comb, remain, curr+1, counter, result);
        comb.pop_back();
        remain += curr;
        counter[curr]++;
    }
 
    backtrack(comb, remain, curr+1, counter, result);
}
    
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) 
{

    vector<int> counter(MAX_NUM+1);
        
    for(int i = 0; i < n; i++) 
    {
        counter[arr[i]]++;
    }
    
    vector<vector<int>> result;
    vector<int> comb;
        

    backtrack(comb, target, 1, counter, result);
    
    return result;
}
