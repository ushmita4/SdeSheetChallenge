
#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
void fenwickUpdate(int index, int siz, vector<long long> &fenwick)
{
    while (index <= siz)
    {
        // Update the current element in the fenwick vector.
        fenwick[index] += 1;

        // Increase the index to the child index in the fenwick tree.
        index = index + (index & (-index));
    }
}
long long fenwickSum(int index, vector<long long> &fenwick)
{
    long long sum = 0;
    while (index > 0)
    {

        // Add the value of current node in sum.
        sum += fenwick[index];

        // Move to the parent node of the current node.
        index = index - (index & (-index));
    }
    return sum;
}

long long getInversions(long long *arr, int n) {

    // Take a 2D vector to store the sorted array and their initial index.
    vector<vector<int>> mapping(n, vector<int>(2));

    vector<long long> fenwick(n + 1, 0), mask(n);

    for (int i = 0; i < n; i++) {
        mapping[i][0] = arr[i];
        mapping[i][1] = i;
    }

    // Sort the mapping array and update all the permutations to mask vector.
    sort(mapping.begin(), mapping.end());
    for (int i = 0; i < n; i++) {
        mask[mapping[i][1]] = i + 1;
    }

    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {

        // Calculate the number of elements greater than the current element.
        answer += fenwickSum(mask[i] - 1, fenwick);

        // Update the element that has been visited.
        fenwickUpdate(mask[i], n, fenwick);
    }
    return answer;
}
