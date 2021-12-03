/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/FOUR21C/problems/S07E09
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
        lli n, i, maxTime = 0, minElement;
        cin >> n;
        vector<int> vec(n);
        for (i = 0; i < n; i++)
            cin >> vec[i];

        minElement = *min_element(vec.begin(), vec.end());
        maxTime = minElement * n; // minimum num of times the bowl rotates

        for (i = 0; i < n; i++)
            if (vec[i] > minElement)
                maxTime++;

        cout << maxTime << endl;
    }

    return 0;
}