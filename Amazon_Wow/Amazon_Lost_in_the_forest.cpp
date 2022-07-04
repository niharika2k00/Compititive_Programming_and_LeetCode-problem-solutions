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

struct cmp
{
    int val = -1;
};

unordered_map<int, cmp> dp;

int Result(int n)
{
    if (n == 1)
        return 1;

    if (dp[n].val != -1)
        return dp[n].val;

    int a;
    if (n % 2 == 0)
        a = 1 + Result(n / 2);
    else
        a = 1 + Result(3 * n + 1);

    return dp[n].val = a;
}

int helper(int m)
{
    int ans = 0, res = 0;
    for (int i = 1; i <= m; i++)
    {
        int temp = Result(i);

        if (temp >= ans)
        {
            ans = temp;
            res = i;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m = 10;

    int res = helper(m);
    cout << "Answer : " << res << endl;

    return 0;
}