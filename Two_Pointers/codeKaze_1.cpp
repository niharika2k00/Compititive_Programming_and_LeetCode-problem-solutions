/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
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

    vector<vector<int>> res;
    vector<int> temp;

    for (int k = 0; k < n; k++)
    {
        if (i + k < n && j + k < n)
            arr[i + k][j + k] = 1;

        if (i - k >= 0 && j - k >= 0)
            arr[i - k][j - k] = 1;
    }

    for (int k = 0; k < n; k++)
    {
        if (i + k < n && j - k >= 0)
            arr[i + k][j - k] = 1;

        if (i - k >= 0 && j + k < n)
            arr[i - k][j + k] = 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int h = 0; h < n; h++)
        {
            if (arr[k][h] == 1)
            {
                // cout << k << " " << h;
                for (int k = 0; k < n; k++)
                {
                    for (int h = 0; h < n; h++)
                    {
                        if (arr[k][h] == 1)
                        {
                            temp.push_back(k);
                            temp.push_back(h);
                        }
                    }
                    res.push_back(temp);
                    temp = {};
                }
            }
        }
    }

    for (int k = 0; k < n; k++)
        for (int h = 0; h < N; h++)
            arr[k][h] = 0;
