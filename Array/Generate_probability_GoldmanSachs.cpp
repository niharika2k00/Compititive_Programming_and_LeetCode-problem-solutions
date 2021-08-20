/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :   https://www.geeksforgeeks.org/generate-0-1-25-75-probability/ 
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

// Random Function to that returns 0 or 1 with equal probability
int rand50()
{
    // rand() function will generate odd or even
    // number with equal probability. If rand()
    // generates odd number, the function will
    // return 1 else it will return 0.

    // int a = rand();
    // cout << "a = " << endl;

    return rand() & 1;
}

bool rand75()
{
    return rand50() | rand50();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    srand(time(NULL));
    unsigned char a = 6, b = 11;

    // The result is 010
    printf("a = %d, b = %d   , a & b = %d\n", a, b, a & b);

    for (int i = 0; i < 20; i++)
        cout << rand75() << "\t";

    return 0;
}