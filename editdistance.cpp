

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    int **dp = new int *[n + 1];

    
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[m + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
          
            if (i == 0)
            {
                dp[i][j] = j;
            }

            else if (j == 0)
            {
                dp[i][j] = i;
            }

           
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

           
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1],
                                       dp[i - 1][j]),
                                   dp[i - 1][j - 1]);
            }
        }
    }
    int ans = dp[n][m];

    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;
    return ans;
}
