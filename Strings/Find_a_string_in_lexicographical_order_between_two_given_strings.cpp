
/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/find-string-lexicographic-order-given-two-strings/  
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

string findString(string s, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != 'z')
        {
            s[i]++;
            return s;
        }
        // if 'z', change it to 'a'
        s[i] = 'a';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a = "aaa", b = "ccd", response;
    int len = a.length();
    response = findString(a, len);
    if (response != b)
        cout << response << endl;
    else
        cout << "-1\n";
    return 0;
}
