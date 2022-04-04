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

//  Recursive Approach
int LCS_Recursive(string x, string y, int m, int n, int count)
{
    if (m == 0 || n == 0)
        return count;

    if (x[m - 1] == y[n - 1]) // check last character
        count = LCS_Recursive(x, y, m - 1, n - 1, count + 1);

    else
        count = 0;

    int maxLength = max(LCS_Recursive(x, y, m - 1, n, 0), LCS_Recursive(x, y, m, n - 1, 0)); //  if not same then Count Break means again start from 0
    count = max(count, maxLength);

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x = "abcdgh", y = "abedfh";
    int m = x.length(), n = y.length();

    int lenRecursiveWay = LCS_Recursive(x, y, m, n, 0);

    cout << "Length of the Longest Common Substring: " << lenRecursiveWay << endl; //  Continuous Order

    return 0;
}