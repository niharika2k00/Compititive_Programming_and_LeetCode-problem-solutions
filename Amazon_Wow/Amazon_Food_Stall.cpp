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

int coupons(int n, int m, int (*stallCoupons)[10], int (*personCoupons)[10], int q, int queries[1][2])
{
    int res = 0;

    for (int i = 0; i < q; i++)
    {
        int person = queries[i][0];
        int stall = queries[i][1];

        for (int j = 0; j < 10; j++)
        {
            if (personCoupons[person - 1][j] == 1 && stallCoupons[stall - 1][j] == 1)
            {
                res += 1;
                break;
            }
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1, m = 1;
    int stallCoupons[m][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int personCoupons[n][10] = {{1, 0, 0, 1, 0, 0, 0, 0, 0, 0}};
    int q = 1;
    int queries[q][2] = {{1, 1}};

    int ans = coupons(n, m, stallCoupons, personCoupons, q, queries);
    cout << "Sum of the queries: " << ans << endl;

    return 0;
}