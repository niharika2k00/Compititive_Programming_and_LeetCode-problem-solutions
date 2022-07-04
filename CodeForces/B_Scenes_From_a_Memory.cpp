/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://codeforces.com/contest/1562/problem/B
 Time Complexity :  
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

bool isPrime(ll num)
{
    ll i;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0) // not prime
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        string s;
        ll n, i, len, j, flag = 0;
        cin >> n >> s;
        len = s.length(); // n == len

        for (i = 0; i < len; i++)
        {
            if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7')
            {
                cout << "1\n";
                cout << s[i] << endl;
                flag = 1;
                break;
            }
        }

        if (flag)
            continue;

        for (i = 0; i < len; i++)
        {
            for (j = i + 1; j < len; j++)
            {
                ll K = (s[i] - '0') * 10 + (s[j] - '0'); // jst to convert string to int
                // cout << " k = " << K << endl;
                if (!isPrime(K)) // not prime  --> means Composite
                {
                    cout << "2\n";
                    cout << s[i] << s[j] << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }

    return 0;
}

/* 

EXPLAINATIONS :: 

- First loop responsible for that a digit in a  number doesnt contain 2 3 5 7, then we will print it as AIM : print the NON PRIME SMALLEST NUMBER 
- If every individual digit of the number contains a prime num then Check its pair with 2 DIGITS ----- in LOOP 2


 */