long countWaysToMakeChange(int *denominations, int n, int value)
{
    
    long *dp = new long[value + 1]();
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = denominations[i]; j <= value; j++)
        {
            dp[j] += dp[j - denominations[i]];
        }
    }

    return dp[value];
}
