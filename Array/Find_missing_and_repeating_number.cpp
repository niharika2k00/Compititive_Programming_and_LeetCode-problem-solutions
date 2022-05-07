/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
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

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    vector<bool> freq(n + 1, false);
    int repeat, missing;

    // traversing the arr
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] != true)
            freq[arr[i]] = true;
        else
            repeat = arr[i];
    }

    // traversing the freq
    for (int i = 1; i < n + 1; i++)
    {
        if (freq[i] == false)
        {
            missing = i;
            break;
        }
    }

    return {missing, repeat}; // make_pair(a . b) also valid
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr{1, 3, 5, 4, 4};
    int len = arr.size();

    pair<int, int> res;
    res = missingAndRepeating(arr, len);

    cout << "\nMissing Number = " << res.first << " \tRepeating Number = " << res.second << endl;

    return 0;
}