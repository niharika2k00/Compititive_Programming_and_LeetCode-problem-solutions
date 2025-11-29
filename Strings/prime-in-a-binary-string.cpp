/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/JAN221C/problems/PINBS
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        string S;
        int flag = 0, len = S.length();
        cin >> S;

        //  1 is Not Prime
        if (len == 1 && S[0] == '1' || len == 1 && S[0] == '0')
            flag = 0;

        //  means if 2 , 3 , 5  present, then its having a PRIME Number
        int isPresentTwo = S.find("10");
        int isPresentThree = S.find("11");
        int isPresentFive = S.find("101");

        if (isPresentTwo != string::npos || isPresentThree != string::npos || isPresentFive != string::npos)
            flag = 1;

        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

//   string :: npos   -->  means until the end of the string.