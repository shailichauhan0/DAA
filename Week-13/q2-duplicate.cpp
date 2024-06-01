#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cout << "Enter the window size k: ";
        cin >> k;

        unordered_set<int> window;
        bool duplicateFound = false;

        for (int i = 0; i < n; i++) {
            if (window.find(arr[i]) != window.end()) {
                duplicateFound = true;
                break;
            }

            window.insert(arr[i]);

            if (window.size() > k) {
                window.erase(arr[i - k]);
            }
        }

        if (duplicateFound) {
            cout << "Duplicate present in window k" << endl;
        } else {
            cout << "Duplicate not present in window k" << endl;
        }
    }

    return 0;
}
