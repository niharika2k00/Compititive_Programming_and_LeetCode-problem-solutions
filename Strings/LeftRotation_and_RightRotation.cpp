/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/left-rotation-right-rotation-string-2/#:~:text=Method%231%3A%20A%20Simple%20Solution,characters%2C%20then%20copy%20n%2Dd%20characters.
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

void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

// In-place rotates s towards right by d
void rightrotate(string &s, int d)
{
    int len = s.size();
    leftrotate(s, len - d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1 = "apple"; // pleap
    leftrotate(str1, 3);
    cout << str1 << endl;

    string str2 = "mango"; //  goman
    rightrotate(str2, 2);
    cout << str2 << endl;

    return 0;
}