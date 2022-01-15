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

void TwoPointer(string str, int right, int left)
{
    if (right >= left)
        return;

    swap(str[left], str[right]);
    TwoPointer(str, right + 1, left - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "Niharika";
    int len = str.length();
    cout << "Length of the string: " << len << endl;

    // Two Pointer Approach
    int left = 0, right = len - 1;
    TwoPointer(str, right, left);

    for (auto it : str)
        cout << it << " ";

    return 0;
}