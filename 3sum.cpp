vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>>ans;
  
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int target = K - arr[i];
        int front = i + 1;
        int back = n - 1;

        while (front < back) {
            int sum = arr[front] + arr[back];

           
            if (sum < target) {
                front++;
            }

            else if (sum > target) {
                back--;
            }

            else {
                int x = arr[front];
                int y = arr[back];
                ans.push_back({arr[i], arr[front], arr[back]});

               
                while (front < back && arr[front] == x) {
                    front++;
                }
                
                while (front < back && arr[back] == y) {
                    back--;
                }
            }
        }

        
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return ans;
}
