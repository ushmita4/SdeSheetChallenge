

#include<unordered_map>

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();

  
    vector <int> answer(n - k + 1);

    
    unordered_map<int,int> hashMap;

    
    for (int i = 0; i < k; i++) 
    {
        hashMap[arr[i]] = hashMap[arr[i]] + 1;
    }

   
    answer[0] = hashMap.size();

    
    for (int index = k; index < n; index++) 
    {
        
        int element = arr[index - k];
        hashMap[element] -= 1;

       
        if (hashMap[element] == 0) 
        {
            hashMap.erase(element);
        }

       
        hashMap[arr[index]] = hashMap[arr[index]] + 1;

       
        int windowNumber = index - k + 1;
        answer[windowNumber] = hashMap.size();
    }

   
    return answer;
}
