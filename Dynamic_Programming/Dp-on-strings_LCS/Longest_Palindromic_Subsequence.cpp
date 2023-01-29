/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787
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

//  Memoization - Dp Approach  (Top - Down)
int LPS(string &x, string &y, int m, int rev, vector<vector<int>> &Dp)
{
    if (m == 0 || rev == 0)
        return 0;

    if (Dp[m][rev] != -1)
        return Dp[m][rev];

    if (x[m - 1] == y[rev - 1]) // check last character
        return Dp[m][rev] = 1 + LPS(x, y, m - 1, rev - 1, Dp);

    else
        return Dp[m][rev] = max(LPS(x, y, m - 1, rev, Dp), LPS(x, y, m, rev - 1, Dp));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x = "bbbab";
    int m = x.length();

    string rev = x;
    reverse(rev.begin(), rev.end());
    cout << rev << endl;

    //  M  x  N  Dp matrix  initialises to -1
    vector<vector<int>> Dp(m + 1, vector<int>(m + 1, -1));

    int len = LPS(x, rev, m, m, Dp); // same as LCS just return the reverse of the string.
    cout << "Length of the Longest Palindromic Subsequence: " << len << endl;

    return 0;
}

/*
            Intuition of the Algorithm
         ---------------------------------

         Similar to the LCS algorithm, but here we have only 1 string.
         So, REVERSE the string and find the LONGEST Similar/Common subsequence among both of them.
 */