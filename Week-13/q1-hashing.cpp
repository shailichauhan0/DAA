#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the character array: ";
    cin >> n;

    vector<char> arr(n);
    cout << "Enter the elements of the character array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<char, int> frequency;
    for (char c : arr) {
        frequency[c]++;
    }

    vector<char> distinctChars;
    for (auto pair : frequency) {
        distinctChars.push_back(pair.first);
    }

    sort(distinctChars.begin(), distinctChars.end());

    cout << "Distinct characters in alphabetical order:" << endl;
    for (char c : distinctChars) {
        cout << c << " (" << frequency[c] << ")" << endl;
    }

    return 0;
}
