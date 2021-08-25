/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/  
 Time Complexity :      O(n * k).  -- unoptimised
 Auxiliary Space:       
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

    vector<int> vec = {1, 3, 2, 4, 8};
    int i = 0, k = 2, max = 0, j = 0;

    for (i = 0; i < vec.size() - 1; i++)
    {
        max = vec[i];
        for (j = i + 1; j < i + k; j++) // for finding the Subarray
        {
            if (vec[j] > max)
                max = vec[j];
        }

        cout << max << "\t";
    }

    return 0;
}

/* 

EXPLANATIONS :: 

-  Max  initialises with the 1st element
-  iNNER LOOP  ----> for traversing the Subarray size K
-  Compare the MAX ELEMENT and then Update 

 */