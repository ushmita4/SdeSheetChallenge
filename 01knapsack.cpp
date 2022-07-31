

int maxProfit(vector<int>& values, vector<int>& weights, int n, int w)
{
    vector<int>result(w + 1, 0); 
  
 
    for(int i=0; i < n; i++)
    {
        
        for(int j = w; j >= weights[i]; j--)
        {
            result[j] = max(result[j], values[i] + result[j - weights[i]]);
        }
    }  
     
    
    return result[w]; 
}
