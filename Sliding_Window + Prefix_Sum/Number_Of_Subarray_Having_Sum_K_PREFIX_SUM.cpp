
/*
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
 Utube :   https://www.youtube.com/watch?v=HbbYPQc-Oo4&t=563s

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
    int i, key = -10, n = sizeof(arr) / sizeof(arr[0]), count = 0, currentSum = 0;

    unordered_map<int, int> hash;

    for (i = 0; i < n; i++)
    {
        currentSum = currentSum + arr[i];
        if (currentSum == key)
            count++;

        if (hash.find(currentSum - key) != hash.end()) //  default val of any element in the map is 1
            count = count + hash[currentSum - key];

        hash[currentSum]++;
    }

    cout << "Number of subarrays present whose SUM is equal to Key :  " << count << endl;
    return 0;
}

/*
                              EXPLANATIONS  ::
    1)  Store the Prefix Sum into the HashMap as TC to access an element from it : O(1) ,WHEREAS we can also use Prefix Array but there TC : O(n) (NOT OPTIMISED).
    2)  Check : IF (currentSum - key) element is FOUND / EXIST in the MAP.

 */

/*
   Test Case :
   arr = { 0 , 8 , 0, 8}
   Sum = 8

   Output : 6
*/