#include <bits/stdc++.h>
using namespace std;
void linearsearch(vector<int> nums, int n, int data)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == data)
        {
            cout << "Present " << i+ 1 << endl;
            f = 1;
            break;
        }
    }
    if (f == 0)
        cout << "Not Present " << n << endl;
}
int main()
{
    int t, n, temp, data;
    vector<int> nums;
    cin >> t;
    while (t)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }
        cin >> data;
        linearsearch(nums, n, data);
        t--;
        nums.clear();
    }
}
//TC: O(n)