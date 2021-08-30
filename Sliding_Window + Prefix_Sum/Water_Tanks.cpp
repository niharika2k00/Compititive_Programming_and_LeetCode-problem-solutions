/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/UCO32021/problems/UCODE015  
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        ll n, i, req = 0, maxWaterN = 0, flag = 0;
        cin >> n;
        vector<int> capacity(n);
        vector<int> waterPresent(n);

        for (i = 0; i < n; i++)
            cin >> capacity[i];

        for (i = 0; i < n; i++)
            cin >> waterPresent[i];

        req = capacity[n - 1] - waterPresent[n - 1]; // more  H2O  req
        maxWaterN = waterPresent[n - 1];

        for (i = n - 2; i >= 0; i--)
        {
            if (waterPresent[i] >= req && req > 0)
            {
                cout << capacity[n - 1] << endl;
                flag = 1;
                break;
            }
            else if (waterPresent[i] < req)
            {
                req = req - waterPresent[i];
                maxWaterN = maxWaterN + waterPresent[i];
            }
        }

        if (!flag)
            cout << maxWaterN << endl;
    }

    return 0;
}

/* 
//  Sample Test Case :: 
a) 1
   3
   4 3 5
   3 2 2

   output : 5

 b)  1
     5 6
     2 3

     output : 5

 c)  2 3 2
     1 3 1

     output : 2  
 */