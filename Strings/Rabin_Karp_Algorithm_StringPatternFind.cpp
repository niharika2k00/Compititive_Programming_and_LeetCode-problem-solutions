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
#define d 10

void rabinKarpSearch(char mainString[], char substr[], int q)
{
    int m = strlen(substr), n = strlen(mainString), i, j, subStringHashVal = 0, mainStringHashVal = 0, h = 1;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for substr and mainString
    for (i = 0; i < m; i++)
    {
        subStringHashVal = (d * subStringHashVal + substr[i]) % q;
        mainStringHashVal = (d * mainStringHashVal + mainString[i]) % q;
    }

    // Find the match
    for (i = 0; i <= n - m; i++)
    {
        if (subStringHashVal == mainStringHashVal) //  if Hash Values equal then STRING CHECK
        {
            for (j = 0; j < m; j++)
                if (mainString[i + j] != substr[j])
                    break;

            if (j == m)
                cout << "substr is found at position: " << i + 1 << endl;
        }

        if (i < n - m)
        {
            mainStringHashVal = (d * (mainStringHashVal - mainString[i] * h) + mainString[i + m]) % q;

            if (mainStringHashVal < 0)
                mainStringHashVal = (mainStringHashVal + q);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char mainString[] = "ABCCDDAEFG";
    char subStr[] = "CDD";
    int q = 13; // a random prime number

    rabinKarpSearch(mainString, subStr, q);

    return 0;
}