#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
    int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) 
  {
    if (set.find(str[r]) != set.end()) 
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}
