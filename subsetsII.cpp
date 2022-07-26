/*
    Time Complexity: O(2^N)
    Space Complexity: O(2^N)

    where ‘N’ is the number of elements in ‘ARR’.  
*/

#include<algorithm>

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> subsets;
    sort(arr.begin(), arr.end());

    subsets.push_back({});
    
    int i = 0;
    while (i < n){

        // Counting the frequency.
        int c = 0;
        while (i+c < n && arr[i] == arr[i+c]){
            c = c + 1;
        }        

        int m = subsets.size();

        for (int j = 0; j < m; j++){
            vector<int> cur = subsets[j];
            
            for (int k = 1; k < c+1; k++){
                cur.push_back(arr[i]);
                subsets.push_back(cur);
            }
        }

        i = i + c;
    }
    
    sort(subsets.begin(), subsets.end());
    return subsets;
}
