#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findLCS(string sequence1, string sequence2) {
    int m = sequence1.length();
    int n = sequence2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sequence1[i - 1] == sequence2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (sequence1[i - 1] == sequence2[j - 1]) {
            lcs = sequence1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}

int main() {
    string sequence1, sequence2;
    cout << "Enter sequence 1: ";
    getline(cin, sequence1);
    cout << "Enter sequence 2: ";
    getline(cin, sequence2);

    string lcs = findLCS(sequence1, sequence2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of LCS: " << lcs.length() << endl;

    return 0;
}
