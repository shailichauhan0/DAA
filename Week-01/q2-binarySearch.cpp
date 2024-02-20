#include <bits/stdc++.h>
using namespace std;
void binarysearch(vector<int> v, int n, int data)
{
    int high = n;
    int low = 0;
    int mid, f = 0, c = 0;
    while (high > low)
    {
        c++;
        mid = low + (high-low) / 2;
        if (v[mid] == data)
        {
            cout << "Present " << c + 1 << endl;
            return;
        }
        else if (v[mid] > data)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "Not Present " << c + 1 << endl;
}
int main()
{
    int t, n, temp, data;
    vector<int> v;
    cin >> t;
    while (t)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        cin >> data;
        binarysearch(v, n, data);
        t--;
        v.clear();
    }
}

//TC: O(nlogn)