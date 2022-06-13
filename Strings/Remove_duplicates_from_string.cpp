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

//  METHOD - I
//  Using HashMapp   O(n)
string Method_1(string &str, int len)
{
    unordered_map<char, int> map;
    int k = 0;

    for (int i = 0; i < len; i++)
    {
        if (map[str[i]] == 0) //  If not present in the Map then Insert.
        {
            map[str[i]]++;
            str[k++] = str[i];
        }
        else if (map[str[i]] > 0)
        {
            // erase ( idx,  len )
            str.erase(str.begin() + i); // delete char @ position
            i--;
            // cout << str << endl;
        }
    }

    return str;
    // return str.erase(k, len - k);
}

//  METHOD - II
//  Using Set   O(n)
string Method_2(string &str, int len)
{
    unordered_set<char> s;

    for (auto it : str)
        s.insert(it);

    int i = 0;
    for (auto val : s)
        str[i++] = val;

    return str.erase(i, len - i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "geeksforgeeks";
    int len = str.length();
    string str1;

    // str1 = Method_1(str, len);
    // str1 = Method_2(str, len);

    cout << "\nAfter removing duplication from the String  ==>  " << Method_1(str, len) << "\n\n";

    return 0;
}