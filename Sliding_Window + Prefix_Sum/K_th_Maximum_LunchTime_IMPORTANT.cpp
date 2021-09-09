/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/LTIME99C/problems/KMAX2  
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
        ll n, i, largeEle, k, maxEle = INT_MIN, result = 0;
        cin >> n >> k;
        vector<ll> vec(n);
        // ll vec[n];

        for (i = 0; i < n; i++)
            cin >> vec[i];

        maxEle = *max_element(vec.begin(), vec.end());
        // cout << maxEle << endl;

        // for (i = 0; i < n; i++)
        // maxEle = max(maxEle, vec[i]);

        for (i = k - 1; i < n; i++) // 2
        {
            if (vec[i] == maxEle)
                result = n - i;
        }

        cout << result << endl;
    }

    return 0;
}

/* 
 test case : 
a) 
1
4 2
2 5 6 1

2 answer
(5 6 1 , 5 6)


b)
7 3 
1 2  3 4 5 2 4

answer : max element = 5
         so subarray will have ele 5 in the 3rd POSITION always
         [3 4 5] , [3 4 5 2]  , [3 4 5 2 4]

EXPLANATION :: 

- K th element is MAXIMUM in the subarray like  3 4 5 , so 5 is the MAX ELE in that subarray of 3 digits 3  4 5
- take the max element of the entire array

 */