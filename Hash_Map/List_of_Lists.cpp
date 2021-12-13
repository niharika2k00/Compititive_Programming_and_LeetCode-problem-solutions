/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/DEC21C/problems/LISTLIST
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

void solve()
{
    ll n, i, maxFreq = -1, remainingEle = 0, maxEle = 0, minOperation = 0;
    cin >> n;
    vector<ll> v(n);
    map<int, int> hashMap; // Order frequency count
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        hashMap[v[i]]++;
    }

    for (auto &it : hashMap)
        if (it.second > maxFreq)
        {
            maxEle = it.first;
            maxFreq = it.second;
        }

    // cout << maxEle << " " << maxFreq << endl;
    remainingEle = n - maxFreq;
    minOperation = (remainingEle - 1) + 2;

    // Base Case
    if (n == 1 || maxFreq == n)
        cout << "0\n";
    else if (maxFreq >= 2)
        cout << minOperation << endl;
    else
        cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        solve();
    }

    return 0;
}

/*                 EXPLAINATION ::
               --------------------
            1 1 1 4 7 1 9 10 1 1

    1) N = 10 elements out of then any 1 ele is having Maximum Frequency (e.g  1 -> 6 times)
    2) Therefore, NO Operation in those 6 lists
    3) Remaining (10 - 6  = 4), these 4 elements will undergoes multiple Operations.
    4) Take all these remaining elements in a List [4 7 9 10] hence 3 total Operation as we are clumping 4 LIST into ONE. And add 2 MAX-FREQUENCY-ELEMENT both side
    5) Like [ 1  4 7 9 10  1]  ,  Operation = +2
              Thus,  Operation  =  (3 + 2 ) = 5.
 */