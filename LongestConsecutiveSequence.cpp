#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int maxi=0,temp=0,n1;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        temp=arr[i]-1;
        if(s.find(temp)==s.end())
        {
            n1=arr[i];
            while(s.find(n1)!=s.end()){
                n1++;
            }
           maxi=max(maxi,n1-arr[i]); 
        }
    }
    return maxi;
}
