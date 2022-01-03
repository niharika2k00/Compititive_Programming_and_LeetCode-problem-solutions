
/*
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
 Time Complexity: O(n)
 Auxiliary Space: O(n)
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

    int arr[] = {10, 2, -2, -20, 10};
    int i, k = -10, n = sizeof(arr) / sizeof(arr[0]), count = 0, currentSum = 0;

    unordered_map<int, int> hash;

    for (i = 0; i < n; i++)
    {
        currentSum = currentSum + arr[i];
        if (currentSum == k)
            count++;

        // if (currentSum - k) element is FOUND in the map
        // then take that value else by default val of any element in the map is 1
        if (hash.find(currentSum - k) != hash.end())
            count = count + hash[currentSum - k];

        hash[currentSum]++;
    }

    cout << "Number of subarrays present whose SUM is equal to K :  " << count << endl;

    return 0;
}

/*
   Test Case :
   arr = { 0 , 8 , 0, 8}
   Sum = 8

   Output : 6
 */