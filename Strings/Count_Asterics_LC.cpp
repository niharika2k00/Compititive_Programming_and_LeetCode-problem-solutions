/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/contest/biweekly-contest-81/problems/count-asterisks/
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

int countAsterisk(string &str, int len)
{
    int i, count = 0;
    bool flag = 1;

    for (auto &ch : str)
    {
        if (ch == '|')
            flag = !flag;
        else if (flag && ch == '*')
            count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "l|*e*et|c**o|*de";
    int len = str.length();

    int res = countAsterisk(str, len);

    cout << res << endl;

    return 0;
}