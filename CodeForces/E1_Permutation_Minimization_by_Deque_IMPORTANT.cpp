/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://codeforces.com/contest/1579/problem/E1
 Time Complexity :  
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
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

    test
    {
        int i, n;
        cin >> n;
        vector<int> arr(n);
        deque<int> deque;
        for (i = 0; i < n; i++)
            cin >> arr[i];

        deque.push_back(arr[0]); //  Push 1st element

        for (i = 1; i < n; i++)
        {
            if (arr[i] < deque.front())
                deque.push_front(arr[i]);
            else
                deque.push_back(arr[i]);
        }

        for (auto it : deque)
            cout << it << ' ';

        cout << endl;
    }
    return 0;
}