

#include <algorithm>

int expandAroundCenter(string str, int left, int right) 
{
    int start = left, end = right;
    int n = str.length();

  
    while (start >= 0 && end < n && str[start] == str[end]) 
    {
        start--;
        end++;
    }

    return end - start - 1;
}

string longestPalinSubstring(string str)
{
    int n = str.length();

    if (n < 1) 
    {
        return "";
    }

    int start = 0, end = 0;

    for (int i = 0; i < n; i++) 
    {
        
        int len1 = expandAroundCenter(str, i, i);

        
        int len2 = expandAroundCenter(str, i, i + 1);

        int len = max(len1, len2);

        
        if (len > end - start + 1) 
        {
            start = i - (len - 1) / 2;
            end = i + (len) / 2;
        }

    }

    return str.substr(start, end - start + 1);
}
