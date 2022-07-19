
#include<bits/stdc++.h>

void findMedian(int arr[], int n)
{
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> higherHalf;

    int median;

    
    for(int size=1; size<=n; size++)
    {
        if(!lowerHalf.empty() && lowerHalf.top() > arr[size-1])
        {    
            
            lowerHalf.push(arr[size-1]);

            if(lowerHalf.size() > higherHalf.size() + 1)
            {    
                
                higherHalf.push(lowerHalf.top());
                lowerHalf.pop();
            }
        }
        else
        {
            higherHalf.push(arr[size-1]);

            if(higherHalf.size() > lowerHalf.size() + 1)
            {    
                
                lowerHalf.push(higherHalf.top());
                higherHalf.pop();
            }
        }
        
    
        if(size%2 == 1)
        {    
            if(higherHalf.size() > lowerHalf.size())
            {
                median = higherHalf.top();
            }
            else
            {
                median = lowerHalf.top();
            }
        }
        else
        {
            median = (lowerHalf.top() + higherHalf.top())/2;
        }
        
     
        cout << median << " ";
    }
}

