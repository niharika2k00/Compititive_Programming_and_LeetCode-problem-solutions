/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/problems/squares-of-a-sorted-array/  
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

    vector<int> arr{-4, -1, 0, 3, 10};
    int i, left = 0, len = arr.size(), right = len - 1, index = len - 1;
    vector<int> ans(len);

    while (left <= right)
    {
        if (abs(arr[left]) > abs(arr[right]))
        {
            ans[index] = abs(arr[left] * arr[left]);
            left++;
            index--;
        }
        else
        {
            ans[index] = abs(arr[right] * arr[right]);
            right--;
            index--;
        }
    }

    for (auto i : ans)
        cout << i << "\t";

    return 0;
}