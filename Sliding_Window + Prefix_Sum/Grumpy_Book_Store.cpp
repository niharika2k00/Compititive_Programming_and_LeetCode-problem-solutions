/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :   https://leetcode.com/problems/grumpy-bookstore-owner/ 
 Time Complexity :    O (n)
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

    // ------------  Test Cases   ---------------
    vector<int> customer = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};

    // vector<int> customer = {4, 10, 10};
    // vector<int> grumpy = {1, 1, 0};
    // --------------------------------------------

    int sum = 0, i, len = customer.size(), minutes = 3; // minutes is our window size

    // Sum of all the indexes which are Not Grumpy === 0
    for (i = 0; i < len; i++)
        if (grumpy[i] == 0)
            sum = sum + customer[i];

    for (i = 0; i < minutes; i++)
        if (grumpy[i] == 1)
            sum = sum + customer[i];

    int maxVal = max(sum, INT_MIN);

    for (i = minutes; i < len; i++)
    {
        if (grumpy[i] == 1)
            sum = sum + customer[i];

        if (grumpy[i - minutes] == 1)
            sum = sum - customer[i - minutes];

        maxVal = max(maxVal, sum);
    }

    cout << maxVal << endl;

    return 0;
}

/* 

EXPLANATIONS :: 

- Add the customers which are not grumpy (have 0 in grumpy vector)
- LOOP from 0 to <k
       add the ones which are grumpy in the prev SUM.

- store in MAXVALUE ( introduced for edge case)

- LOOP from k to <n
       check whether the next ele is grumpy or not 
       check the ( i - k) ele also as we are eliminating it.


 */