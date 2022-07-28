
int matrixMultiplication(vector<int> &arr, int N)
{
   

    int dp[N][N];
  

   
    for (int i = 1; i < N; i++)
    {

        dp[i][i] = 0;
    }
       

     
    for (int l = 2; l < N; l++)
    {
        for (int i = 1; i < N - l + 1; i++)
        {
            int j = i + l - 1;

          
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
               
                int temp = dp[i][k] + dp[k + 1][j]  + arr[i - 1] * arr[k] * arr[j];
                
               
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }

    return dp[1][N - 1];
}
