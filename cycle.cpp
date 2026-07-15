#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bitonic(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> inc(n), dec(n);

    // Length of non-decreasing subarray ending at each index
    inc[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1])
            inc[i] = inc[i - 1] + 1;
        else
            inc[i] = 1;
    }

    // Length of non-increasing subarray starting at each index
    dec[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[i + 1])
            dec[i] = dec[i + 1] + 1;
        else
            dec[i] = 1;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, inc[i] + dec[i] - 1);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Longest Bitonic Subarray Length = " << bitonic(arr) << endl;

    return 0;
}