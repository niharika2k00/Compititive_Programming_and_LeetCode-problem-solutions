/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-11/problems/16713
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

    //   SLIDING WINDOW TECHNIQUE
    //   Finding Subarray
    //   Find the DISTINCT element in the window size K.
    int i, windowSize = 2, len = 4, distinct = 0;
    vector<int> vec{1, 2, 2, 4}, result;
    unordered_map<int, int> hashMap;

    for (i = 0; i < windowSize; i++)
    {
        if (hashMap[vec[i]] == 0)
            distinct++;

        hashMap[vec[i]]++;
    }

    result.push_back(distinct);

    for (i = windowSize; i < len; i++)
    {
        if (hashMap[vec[i - windowSize]] == 1) // means occur only 1 time
            distinct--;

        hashMap[vec[i - windowSize]]--; //  remove ele

        if (hashMap[vec[i]] == 0)
            distinct++;

        hashMap[vec[i]]++;

        result.push_back(distinct);
    }

    for (auto i : result)
        cout << i << "\t";

    return 0;
}