
/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define loop1(n) for (ll i = 0; i < (n); i++)
#define loop2(n) for (ll i = 1; i <= (n); i++)
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Print the first negative number of every window of K size .

    int arr[] = {-2, -8, 3, 4, 10, -6, 5, -1};
    deque<int> storeNegativeIndex;
    int n = 8, k = 3, count = 0, i = 0;

    for (i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            storeNegativeIndex.push_back(i);
    }

    for (i = k; i < n; i++)
    {
        if (!storeNegativeIndex.empty())
            cout << arr[storeNegativeIndex.front()] << "\t";
        else
            cout << "0\t";

        // Remove the elements  from the FRONT which are out of the current new window
        while (!storeNegativeIndex.empty() && (storeNegativeIndex.front() <= (i - k)))
            storeNegativeIndex.pop_front();

        if (arr[i] < 0)
            storeNegativeIndex.push_back(i);
    }

    if (!storeNegativeIndex.empty())
        storeNegativeIndex.push_back(i);
    else
        cout << "0 \t";

    return 0;
}