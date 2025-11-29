/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 0, 1, 0, 0, 1
    int arr[] = {0, 1, 1, 0, 1, 1}, size = sizeof(arr) / sizeof(arr[0]), sum = 0, maxLength = -1, endIndex = -1, i;
    unordered_map<int, int> map;

    for (i = 0; i < size; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];

        if (sum == 0) //   subarray found with the given criteria
        {
            maxLength = max(maxLength, i + 1);
            endIndex = i;
        }

        //  If Sum exist before in the MAP
        if (map.find(sum) != map.end())
        {
            // maxLength =  max(maxLength, i-map[sum]);
            if (i - map[sum] > maxLength)
            {
                maxLength = i - map[sum];
                endIndex = i;
            }
        }
        else
            map[sum] = i;
    }

    cout << " MaxLength of equal number of 0 & 1 : " << maxLength << "\n\n Start index : " << (endIndex - maxLength + 1) << "\n End index : " << endIndex << endl;

    return 0;
}

//   Contiguous Array     <-------      LEETCODE PROBLEM similar        https://leetcode.com/problems/contiguous-array/