int findMinimumCoins(int amount) 
{
    // Write your code here
   int ans=0;
   int n=9;
   int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
   for(int i=n-1;i>=0;i--){
       while(amount>=coins[i]){
           amount=amount-coins[i];
           ans++;
       }
   }
    return ans;
}
