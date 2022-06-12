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

//  METHOD - I
string Method_1(string &str, int len)
{
    unordered_map<char, int> map;
    int k = 0;

    for (int i = 0; i < len; i++)
    {
        if (map[str[i]] == 0) //  If not present in the Map then Insert.
        {
            map[str[i]]++;
            str[k++] = str[i];
        }
    }

    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "geeksforgeeks";
    int len = str.length();

    string str1 = Method_1(str, len);

    cout << "\nAfter removing duplicated from the String  ==>  " << Method_1(str, len) << "\n\n";

    return 0;
}