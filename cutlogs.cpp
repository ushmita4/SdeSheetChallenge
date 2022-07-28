

#include <vector>

int cutLogs(int k, int n)
{    
    
    vector<int> dp(n + 1);

    for(int i=0; i <= n; i++)
    {
        dp[i] = i;
    }
    
    
    for(int i=2; i <= k; i++)
    {    
        
        vector<int> dp2(n + 1);
        int t = 1;
        
       
        for(int j=1; j <= n; j++)
        {
            while(t < j and max(dp[t - 1], dp2[j - t]) > max(dp[t], dp2[j - t - 1]))
            {
                t++;
            }
            dp2[j] = 1 + max(dp[t - 1], dp2[j - t]);
        }
        
     
        dp = dp2;
    }
    
   
    return dp[n];
}

