#include<map>
#include<queue>
#include<algorithm>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    if (k == n) {
        return arr;
    }

    map<int, int> mp;

    
    for (int ele : arr) {

        mp[ele]++;
    }

   
    priority_queue<pair<int,int>> heap;

    // Build heap of maximum size 'K'.
    for (auto x : mp) {
        heap.push({x.second, x.first});
    }

    vector<int> ans(k);

    // Build output array.
    for (int i = 0; i < k; i++) {

        ans[i] = heap.top().second;
        heap.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}
