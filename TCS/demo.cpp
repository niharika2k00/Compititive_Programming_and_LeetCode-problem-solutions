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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c[3][20] = {"Espresso Coffee", "Cappuccino Coffee", "Latte Coffee"};

    char t[8][30] = {"Plain Tea", "Assam Tea", "Ginger Tea", "Cardamom Tea", "Masala Tea", "Lemon Tea", "Green Tea", "Organic Darjeeling Tea"};

    char s[4][20] = {"Hot and Sour Soup", "Veg Corn Soup", "Tomato Soup", "Spicy Tomato Soup"};

    char ch = 'c';
    int item = 1, i;

    // cout << ch << item << endl;

    if (ch == 'c')
    {
        if (item - 1 > 2)
            cout << "INVALID INPUT" << endl;

        else
            cout << "Welcome to CCD!\nEnjoy your " << c[item - 1] << " ! " << endl;
    }

    if (ch == 't')
    {
        if (item - 1 > 7)
            cout << "INVALID INPUT" << endl;

        else
            cout << "Welcome to CCD!\nEnjoy your " << t[item - 1] << " ! " << endl;
    }

    if (ch == 's')
    {
        if (item - 1 > 3)
            cout << "INVALID INPUT" << endl;

        else
            cout << "Welcome to CCD!\nEnjoy your " << s[item - 1] << " ! " << endl;
    }

    return 0;
}

// https://prepinsta.com/tcs-coding-questions/

// https://prepinsta.com/top-100-codes/

// https://prepinsta.com/tcs-nqt/placement-papers/coding-questions/

// https://www.geeksforgeeks.org/tcs-nqt-coding-sheet-exam-preparation/

// https://www.youtube.com/c/CampusMonkByRachitRastogi