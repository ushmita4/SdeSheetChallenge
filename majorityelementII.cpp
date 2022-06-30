#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int c=arr.size()/3;
    unordered_map<int,int>freqMap;
  
  for (int i=0;i<arr.size();i++) {
    freqMap[arr[i]]++;
  }
    vector<int> res;
    for (auto it : freqMap) {
    if(it.second>c)
        res.push_back(it.first);
  }
    return res;
}
