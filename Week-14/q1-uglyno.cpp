#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getNthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

    for (int i = 1; i < n; i++) {
        int nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        ugly[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = ugly[i2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = ugly[i3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = ugly[i5] * 5;
        }
    }

    return ugly[n - 1];
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cout << "Enter the value of n for test case " << i + 1 << ": ";
        cin >> n;
        int nthUglyNumber = getNthUglyNumber(n);
        cout << "The " << n << "th ugly number is: " << nthUglyNumber << endl;
    }

    return 0;
}
