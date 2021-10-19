/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/k-th-lexicographical-string-of-given-length/  
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

string lexicographicalString(int len, int k)
{
    int i, temp[len] = {0};
    string newString = "";

    for (i = len - 1; i >= 0; i--)
    {
        temp[i] = k % 26;
        k /= 26;
        cout << "k = " << k << endl;
    }

    if (k > 0)
        return "-1";

    for (i = 0; i < len; i++)
        newString += (temp[i] + ('a'));

    return newString;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len = 3, k = 10; // K-th lexicographical string of length len
    // if (pow(26, len) < k)
    //     cout << "-1\n";
    k = k - 1; // bcz stored value start from 0
    cout << lexicographicalString(len, k);

    return 0;
}

/* 
         1) First fill all the indexes wuth 0
         2) then from the back increases lexicographically
          aaaa -> aaab -> aaac            ... like this
 */