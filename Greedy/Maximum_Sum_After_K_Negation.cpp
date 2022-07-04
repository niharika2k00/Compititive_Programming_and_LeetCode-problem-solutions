/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1#  
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

TEST CASE :: 

N = 10, K = 5
arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}

ans :  68

 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k, i, maxSum = 0;
    cin >> n >> k;
    vector<int> vec(n);

    for (i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    // all negative numbers turned into positive
    for (i = 0; i < n; i++)
        if (vec[i] < 0 && k > 0)
        {
            vec[i] = vec[i] * (-1);
            k--;
        }

    sort(vec.begin(), vec.end());

    if (k > 0 && k % 2 != 0) // if ODD number of K remains.
        vec[1] = -vec[1];

    // Summ of all the elements of the vector.
    for (i = 0; i < n; i++)
        maxSum = maxSum + vec[i];

    cout << maxSum << endl;

    return 0;
}