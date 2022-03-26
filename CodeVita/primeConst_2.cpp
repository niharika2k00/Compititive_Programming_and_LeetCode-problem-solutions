/*
______________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :
______________
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

lli find_LCM(lli x, lli y, lli z)
{
    lli max, store, count, flag = 0;

    if (x >= y && x >= z)
        max = x;
    else if (y >= x && y >= z)
        max = y;
    else if (z >= x && z >= y)
        max = z;

    for (count = 1; flag == 0; count++)
    {
        store = max * count;
        if (store % x == 0 && store % y == 0 && store % z == 0)
            flag = 1;
    }

    return store;
}

bool isPrime(lli num)
{
    if (num == 0 || num == 1)
        return false;

    for (lli i = 2; i < sqrt(num); i++)
        if (num % i == 0)
            return false;

    return true;
}

void solve()
{
    lli a, b, c, d, flag, LCM = 0, result = 0, prime;
    cin >> a >> b >> c >> d;
    LCM = find_LCM(a, b, c);

    result = LCM + d;

    prime = isPrime(result);

    if (prime == 1)
        cout << result;
    else if (prime == 0)
        cout << "None";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
