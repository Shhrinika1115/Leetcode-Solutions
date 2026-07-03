#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;

        return 1 + (num - 1) % 9;
    }
};

int main() {
    Solution sol;

    int num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Result: " << sol.addDigits(num);

    return 0;
}