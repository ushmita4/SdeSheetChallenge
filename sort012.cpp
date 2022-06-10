/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where N is the size of the array.
*/

#include <algorithm>

void sort012(int *arr, int n)
{
    int i = 0;
    int nextZero = 0;
    int nextTwo = n - 1;

    while (i <= nextTwo)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[nextZero]);
            i++;
            nextZero++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[nextTwo]);
            nextTwo--;
        }
        else
        {
            i++;
        }
    }
}
