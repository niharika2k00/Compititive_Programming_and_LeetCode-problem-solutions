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
    TwoPointer_StringReverse(str, left + 1, right - 1); // Shifts the Pointer
}

void UsingLoop(string &str, int left, int right)
{
    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

bool CheckPalindrome(string &str, int start, int end)
{
    if (end <= start)
        return true;

    if (str[start] != str[end])
        return false;

    return CheckPalindrome(str, start + 1, end - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "maoam";
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