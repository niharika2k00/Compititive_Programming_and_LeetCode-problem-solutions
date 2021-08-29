/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/START10C/problems/SIGNFLIP  
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
        ll i, n, k, sum = 0, MaxSumResult = 0;
        cin >> n >> k;
        vector<int> vec(n);
        for (i = 0; i < n; i++)
            cin >> vec[i];

        sort(vec.begin(), vec.end());

        for (i = 0; i < n; i++)
        {
            if (vec[i] < 0 && k > 0)
            {
                vec[i] = vec[i] * (-1);
                k--;
            }
        }

        sort(vec.begin(), vec.end(), greater<int>());

        for (i = 0; i < n; i++)
        {
            if (vec[i] >= 0)
                sum = sum + vec[i];
        }

        cout << sum << endl;
    }

    return 0;
}

/* 
EXPLANATIONS :: 

6 2 
6 -10  -1 0 -4 2


Using Greedy Approach.
first SORT the array then convert K element from the beginning by multiplying it with   -1
then again SORT it and greedily take the SUM of all +ve elements

 */