/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
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

    vector<int> nums = {1, 2, 1, 3, 2, 5};
    int i, len = nums.size(), num = 0;
    vector<int> ans[len];
    unordered_set<int> S;

    for (i = 0; i < len; i++)
    {
        cout << nums[i] << endl;
        if (S.find(nums[i]) != S.end())
            S.insert(nums[i]);
        else
            S.erase(nums[i]);
    }

    S.insert(77);
    // cout << S.begin() << endl;

    for (auto number : S)
        cout << number;

    for (auto itr = S.begin(); itr != S.end(); itr++)
        // ans.push_back(*itr);
        cout << *itr << endl;

    return 0;
}