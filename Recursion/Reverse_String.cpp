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

void TwoPointer(vector<int> str, int right, int left)
{
    if (right >= left)
        return;

    if (right > left)
    {
        swap(str[left], str[right]);
        // for (auto it : str)
        //     cout << it << " ";
        TwoPointer(str, right + 1, left - 1);
    }
    // return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // string str = "Niharika";
    // int len = str.length();

    vector<int> vec{1, 2, 3, 4, 5, 6};
    int len = vec.size();
    cout << "Length of the string: " << len << endl;

    // Two Pointer Approach
    int left = 0, right = len - 1;
    cout << TwoPointer(vec, right, left);

    // for (auto it : str)
    // cout << it << " ";

    return 0;
}