#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        // Counting sort array
        vector<int> count(maxCost + 1, 0);

        // Count frequency of each cost
        for (int cost : costs) {
            count[cost]++;
        }

        int bars = 0;

        // Buy cheapest ice creams first
        for (int price = 1; price <= maxCost; price++) {
            while (count[price] > 0 && coins >= price) {
                coins -= price;
                bars++;
                count[price]--;
            }
        }

        return bars;
    }
};

int main() {
    int n, coins;

    cout << "Enter number of ice creams: ";
    cin >> n;

    vector<int> costs(n);

    cout << "Enter costs: ";
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cout << "Enter coins: ";
    cin >> coins;

    Solution obj;
    int result = obj.maxIceCream(costs, coins);

    cout << "Maximum ice creams that can be bought: " << result << endl;

    return 0;
}