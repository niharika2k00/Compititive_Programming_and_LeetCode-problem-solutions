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

    vector<int> nums{1, 2, 1, 3, 2, 5};
    int i, len = nums.size(), num = 0;
    vector<int> ans(len);
    set<int> Set;

    for (i = 0; i < len; i++)
    {
        cout << nums[i] << endl;
        if (Set.find(nums[i]) == Set.end()) // can't find and iterator reaches the end
            Set.insert(nums[i]);
        else
            Set.erase(nums[i]);
    }

    // for (auto it = nums.begin(); it != nums.end(); ++it)
    // cout << ' ' << *it;

    // Set.insert(10);
    // cout << Set.begin() << endl;

    // for (auto number : Set)
    // cout << number;

    for (auto itr = Set.begin(); itr != Set.end(); itr++)
    {
        ans.push_back(*itr);
        cout << *itr << "  ";
    }

    // set<int, greater<int>>::iterator itr;
    // for (auto itr = Set.begin(); itr != Set.end(); itr++)
    // cout << *itr << " ";

    return 0;
}