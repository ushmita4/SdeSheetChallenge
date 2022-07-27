

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
   
    int n = arr.size();
    int m = queries.size();

    vector<int> result(m, -1);

   
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[j] <= queries[i][1]) {
                result[i] = max(result[i], arr[j] ^ queries[i][0]);
            }
        }
    }

    return result;
}
