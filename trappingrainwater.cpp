#include <climits>

long getTrappedWater(long *arr, int n){

    int peak = 0;
    long ans = 0L;


    if (n == 0) {
        return 0L;
    }

    long peakVal = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] >= peakVal) {
            peak = i;
            peakVal = arr[i];
        }
    }

    long maxSoFar = LONG_MIN;
    long countSubmerged = 0L;
    long submergedArea = 0L;

    for (int i = 0; i <= peak; i++) {
        if (arr[i] >= maxSoFar) {

            
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }
    maxSoFar = LONG_MIN;
    countSubmerged = 0L;
    submergedArea = 0L;

    for (int i = n - 1; i >= peak; i--) {
        if (arr[i] >= maxSoFar) {

            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    return ans;
}
