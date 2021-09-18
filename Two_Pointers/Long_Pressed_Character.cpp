/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/problems/long-pressed-name/  
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

    string name = "alex", typed = "aaleex";
    int i, count = 0;
    unordered_map<char, int> mapA;
    unordered_map<char, int> mapB;

    for (i = 0; i < name.length(); i++)
        mapA[name[i]]++;

    for (i = 0; i < typed.length(); i++)
        mapB[typed[i]]++;

    for (i = 0; i < name.length(); i++)
    {
        if (mapA[name[i]] <= mapB[name[i]]) // frequency SAME check
            count++;
        else
        {
            cout << " false" << endl;
            break;
        }
    }

    if (name.length() == count)
        cout << " true" << endl;

    return 0;
}