
/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :   https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3974/ 
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

    // REVERSE  every alphabet  of the String
    string s = "Test1ng-Leet=code-Q!";
    int right = s.size() - 1, left = 0;

    //   ---------------------------
    // TWO POINTER APPROACH
    //   ---------------------------
    while (left < right)
    {
        if (isalpha(s[left]) && isalpha(s[right])) // Both ALPHABET
            swap(s[left++], s[right--]);

        else if (!isalpha(s[left]) && !isalpha(s[right])) // Both NOT ALPHABET
            left++, right--;

        else if (!isalpha(s[left]) && isalpha(s[right])) //  Left --> NOT ALPHABET   , Right --> ALPHABET
            left++;

        else
            right--;
    }

    //   ---------------------------
    // USING STACK APPROACH
    //   ---------------------------
    stack<char> p;
    string str;
    int i;

    for (i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
            p.push(s[i]);
    }

    for (i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            str = str + p.top();
            p.pop();
        }
        else
            str = str + s[i];
    }

    for (auto i : str)
        cout << i << " ";

    return 0;
}