#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, pair<int, int>> productMap;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = arr[i] * arr[j];
            if (productMap.find(product) != productMap.end()) {
                pair<int, int> p = productMap[product];
                if (p.first != arr[i] && p.second != arr[i] && p.first != arr[j] && p.second != arr[j]) {
                    cout << "Pair (a, b): (" << p.first << ", " << p.second << ")" << endl;
                    cout << "Pair (c, d): (" << arr[i] << ", " << arr[j] << ")" << endl;
                    return 0;
                }
            } else {
                productMap[product] = make_pair(arr[i], arr[j]);
            }
        }
    }

    cout << "No such pairs exist" << endl;
    return 0;
}
