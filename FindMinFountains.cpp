#include "mountain.h"

int foundMountain(std::vector<int>& arr, int n) {
    int open = 0;
    int mini = 0;
    int maxi = 0;

    while (maxi < n) {
        for (int i = 0; i <= n; i++) {
            if (i - arr[i] <= mini && i + arr[i] > maxi) {
                maxi = i + arr[i];
            }
        }

        if (maxi == mini)
            return -1;

        open++;
        mini = maxi;
    }

    return open;
}
