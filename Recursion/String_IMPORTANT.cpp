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

void TwoPointer_StringReverse(string &str, int left, int right)
{
    if (right <= left)
        return;

    swap(str[left], str[right]);
    TwoPointer_StringReverse(str, left + 1, right - 1);
}

bool CheckPalindrome(string &str, int front, int len)
{
    if (str[front] != str[len - front]) //  (len - 1 - i)
        return false;

    CheckPalindrome(str, front + 1, len);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "Niharika";
    int len = str.length();

    cout << "Length of the string: " << len << endl;

    // ----------------------------------------------
    // Two Pointer Approach using RECURSION
    // ----------------------------------------------
    int left = 0, right = len - 1;
    TwoPointer_StringReverse(str, left, right);

    cout << "\nReversed String : ";
    for (auto it : str)
        cout << it << " ";

    // ----------------------------------------------
    //  Check Palindromic using RECURSION
    // ----------------------------------------------
    bool ans = CheckPalindrome(str, 0, len - 1);
    if (ans)
        cout << "\n\nGiven string is Palindromic.";
    else
        cout << "\n\nNot a Palindromic String.";

    return 0;
}