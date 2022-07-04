
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, max1 = INT_MIN, max2 = INT_MIN;

    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // for (i = 0; i < n; i++)
    // {
    //     if (arr[i] > max1)
    //     {
    //         max2 = max1;
    //         max1 = arr[i];
    //     }
    //     else if (arr[i] > max2 && arr[i] < max1)
    //         max2 = arr[i];
    // }

    // vector<int>::iterator it;
    // it = find(arr.begin(), arr.end(), max2);

    // cout << (it - arr.begin()) + 1 << endl;

    // --------------------
    //      OR
    //  -------------------

    vector<pair<int, int>> VP(n);

    for (i = 0; i < n; i++)
        VP[i] = {arr[i], i};

    sort(VP.begin(), VP.end());

    for (i = 0; i < n; i++)
        cout << VP[i].first << "\t";

    cout << VP[n - 2].second << "\t"; // index of the second highest number .

    return 0;
}