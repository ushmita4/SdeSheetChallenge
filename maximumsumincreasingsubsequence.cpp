int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int dp[n];
    int totalWeight = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        dp[i] = rack[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            
            if(rack[i] > rack[j] && dp[i] < dp[j] + rack[i])
            {
                dp[i] = dp[j] + rack[i];
            }
        }

        
        totalWeight = max(totalWeight, dp[i]);
    }

    return totalWeight;
}
