/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    // https://leetcode.com/contest/biweekly-contest-59/problems/minimum-time-to-type-word-using-special-typewriter/
________________________________________
----------------------------------------
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

    string word = "bza";
    int len = word.length(), i, sum = 0, val1, val2;
    sum = sum + len;

    //    Calculating the distance of the first letter
    if (word[0] != 'a')
    {
        val1 = abs(word[0] - 'a');
        val2 = 26 - abs('a' - word[0]);
        sum = sum + min(val1, val2);
    }

    for (i = 1; i < len; i++)
    {
        val1 = abs(word[i] - word[i - 1]);
        val2 = 26 - abs(word[i - 1] - word[i]);
        sum = sum + min(val1, val2);
    }

    cout << "sum = " << sum << endl;

    return 0;
}