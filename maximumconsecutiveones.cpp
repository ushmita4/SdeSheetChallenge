int longestSubSeg(vector<int> &arr , int n, int k) 
{ 

   
    int cnt0 = 0;
    int l = 0; 
    int maxLen = 0; 
  
    for (int r = 0; r < n; r++) { 
        if (arr[r] == 0) {
            cnt0++; 
        }
  
        
        while (cnt0 > k) { 
            if (arr[l] == 0) {
                cnt0--; 
            }

            l++; 
        } 
  
        maxLen = max(maxLen, r - l + 1); 
    }
    
    return maxLen; 
} 
