#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string temp = s;

            // Sort the string
            sort(temp.begin(), temp.end());

            // Store original string
            mp[temp].push_back(s);
        }

        vector<vector<string>> ans;

        // Put grouped anagrams into answer vector
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = obj.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";

    for (auto group : result) {
        cout << "[ ";

        for (string word : group) {
            cout << word << " ";
        }

        cout << "]\n";
    }

    return 0;
}