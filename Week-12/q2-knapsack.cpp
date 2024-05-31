#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

void findKnapsackItems(int n, const vector<int>& weights, const vector<int>& values, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxValue = dp[n][capacity];
    vector<Item> selectedItems;
    int i = n, j = capacity;

    // Trace back to find selected items
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back({weights[i - 1], values[i - 1]});
            j -= weights[i - 1];
        }
        i--;
    }

    reverse(selectedItems.begin(), selectedItems.end());

    cout << "Maximum Value: " << maxValue << endl;
    cout << "Selected Items:" << endl;
    for (const auto& item : selectedItems) {
        cout << "Weight: " << item.weight << ", Value: " << item.value << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    findKnapsackItems(n, weights, values, capacity);

    return 0;
}
