
/* 
________________________________________
  - By Niharika Dutta
 Code Link :   https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

     // Find the majority element among the given Vector that have more than N/ 2 occurrences.
________________________________________
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

    vector<int> vec{5, 5, 4, 5, 3};
    unordered_map<int, int> map;
    int i, len = vec.size();

    // --------------------    Using hashmap  --------------------
    // Time Complexity  :      O(n)
    // Space Complexity :      O(n)
    for (i = 0; i < len; i++)
        map[vec[i]]++;

    for (auto i = map.begin(); i != map.end(); i++)
        // cout << i->first << "      " << i->second << endl;
        if (i->second > len / 2)
            cout << i->first << endl;

    // --------------------    Using  Moore's Algorithms  ( BEST CASE ) --------------------
    // Time Complexity  :      O(n)
    // Space Complexity :      O(1)

    int votes = 0, candidates = 0, freq = 0;
    for (i = 0; i < len; i++)
    {
        if (votes == 0)
        {
            candidates = vec[i];
            votes++;
        }
        else
        {
            if (candidates == vec[i]) // if num matches with the prev digit
                votes++;
            else
                votes--;
        }
    }

    for (i = 0; i < len; i++)
        if (vec[i] == candidates)
            freq++;

    if (freq > len / 2)
        cout << candidates << endl;
    else
        cout << "-1" << endl;
    return 0;
}