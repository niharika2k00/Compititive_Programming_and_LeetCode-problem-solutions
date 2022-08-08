/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/sort-array-wave-form-2/
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

    vector<int> vec{15, 20, 1, 2, 3, 4, 5, 7};
    int len = vec.size();
    vector<int> temp(len);
    int index = 0, i = 0, j = len - 1;

    sort(vec.begin(), vec.end());

    while (i <= j)
    {
        temp[index] = vec[j];
        index++;
        temp[index] = vec[i];
        i++;
        j--;
        index++;
    }

    // OR
    /*    for (int i = 0; i < len - 1; i += 2)
           swap(vec[i], vec[i + 1]); */

    for (auto it : temp)
        cout << it << "\t";

    return 0;
}