#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    // Negative numbers and numbers ending with 0 (except 0)
    // cannot be palindromes.
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int rev = 0;

    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return (x == rev || x == rev / 10);
}

int main() {
    int x;

    cout << "Enter a number: ";
    cin >> x;

    if (isPalindrome(x))
        cout << x << " is a Palindrome Number." << endl;
    else
        cout << x << " is NOT a Palindrome Number." << endl;

    return 0;
}