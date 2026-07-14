#include <iostream>
using namespace std;

bool checkPerfectNumber(int num) {
    if (num <= 1)
        return false;

    int sum = 1;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;

            if (i != num / i)
                sum += num / i;
        }
    }

    return sum == num;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (checkPerfectNumber(num))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}