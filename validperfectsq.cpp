#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    long long left = 1, right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num)
            return true;
        else if (square < num)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfectSquare(num))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}