int cutRod(vector<int> &price, int n)
{
    int cost[n + 1];
    cost[0] = 0;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        int maxCost = INT_MIN;

       
        for (j = 0; j < i; j++)
        {
            maxCost = max(maxCost, price[j] + cost[i - j - 1]);
        }

       
        cost[i] = maxCost;
    }

   
    return cost[n];
}
