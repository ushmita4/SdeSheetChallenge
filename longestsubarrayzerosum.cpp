#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector<int>arr) 
{
    
    unordered_map<int, int> presum;
 
    int sum = 0; 
    int maxLen = 0; 
    int n = arr.size();
   
    for (int i = 0; i < n; i++) {
     
        sum += arr[i];
 
        if (arr[i] == 0 && maxLen == 0)
            maxLen = 1;
        if (sum == 0)
            maxLen = i + 1;
 
        
        if (presum.find(sum) != presum.end()) {
           
            maxLen = max(maxLen, i - presum[sum]);
        }
        else {
            
            presum[sum] = i;
        }
    }
 
    return maxLen;
}
