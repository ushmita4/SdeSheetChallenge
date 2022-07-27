#include <unordered_set>
int maximumXor(vector<int> A)
{   
    int ans = 0;
    
    int mask = 0;
    int n = A.size();
    unordered_set<int> s;

    for (int i = 30; i >= 0; i--)
    {   
        

     
        mask = mask | (1 << i);

        for (int j = 0; j < n; j++)
        {   
           
            s.insert(A[j] & mask);
        }

        int tempAns = ans;

        
        tempAns = tempAns | (1 << i);

        for(auto it: s)
        {   
           
            if(s.count(it ^ tempAns))
            {   
                ans = tempAns;
                break;
            }
        }

        s.clear();
    } 

    return ans;
}
