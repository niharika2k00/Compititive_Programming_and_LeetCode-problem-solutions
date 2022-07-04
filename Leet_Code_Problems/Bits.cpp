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

/*
      _________________________________
        A       B      AND      OR
      _________________________________
        0       0       0        0
        0       1       0        1
        1       0       0        1
        1       1       1        1

 */

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int counting01(int num)
{
    int zero = 0, one = 0;
    while (num > 0)
    {
        if (num & 1)
            one++;
        else
            zero++;

        num = num >> 1;
    }

    return zero;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 6;

    int totalBits = (int)log2(num) + 1;
    int oneCount1 = __builtin_popcount(num); // TC   O(num)

    // Brian Kernighan’s Algorithm:   TC   O(k)
    int oneCount2 = countSetBits(num);

    counting01(num); //   TC   O(log N)

    cout << "Total Bits in its Binary Number : " << totalBits << endl
         << "Number of 1's : " << oneCount << endl;

    return 0;
}