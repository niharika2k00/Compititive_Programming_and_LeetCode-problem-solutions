/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/survival/
 Time Complexity :
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

/*
 N – Maximum unit of food you can buy each day.
 S – Number of days you are required to survive.
 M – Unit of food required each day to survive. ( Food/day)

 Find the minimum number of days on which you need to buy food from the shop so that you can survive the next S days

  */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, m, totalFoodReq, days;
    cin >> n >> s >> m;

    // if per day food req >  buy /day
    if (m > n)
        cout << "Cannot SURVIVE for " << s << " days. " << endl;

    // Total food Req. for 7 days >  Max food can buy for 6 days
    else if (7 * m > 6 * n && s > 6)
        cout << "Cannot SURVIVE for " << s << " days. " << endl;

    else
    {
        totalFoodReq = (s * m);
        days = ceil(totalFoodReq / n);
        if (totalFoodReq % n != 0)
            days++;
        cout << "Can SURVIVE for " << s << " days. " << endl;
    }

    return 0;
}

/*
TestCase ::
16 10 2
Can SURVIVE for 10 days.
*/