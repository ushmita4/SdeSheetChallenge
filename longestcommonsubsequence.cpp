

int LCSHelper(string str1, int n, string str2, int m)
{
    int **dp = new int *[2];

    dp[0] = new int[m + 1];
    dp[1] = new int[m + 1];

    int currRowParity = 0;

    for (int i = 0; i <= n; i++)
    {
        currRowParity = i % 2;

        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[currRowParity][j] = 0;
            }
            else if (str1[i - 1] != str2[j - 1])
            {
                

                dp[currRowParity][j] =
                    max(dp[1 - currRowParity][j],
                        dp[currRowParity][j - 1]);
            }
            else
            {
                
                dp[currRowParity][j] = dp[1 - currRowParity][j - 1] + 1;
            }
        }
    }

    int ans = dp[currRowParity][m];

    delete[] dp[0];
    delete[] dp[1];
    delete[] dp;

    return ans;
}

int lcs(string str1, string str2)
{
    return LCSHelper(str1, str1.length(), str2, str2.length());
}
