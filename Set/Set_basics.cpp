
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

    // set<int> setCopy;
    set<int, greater<int>> s;
    // unordered_set<int> setCopy;

    s.insert(0);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    // s.insert(20);
    // s.insert(42);
    // s.insert(10);
    // s.insert(77);
    // s.insert(16);
    // s.insert(100);

    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << "\t";
    cout << "\n";

    set<int> setCopy(s.begin(), s.end());

    // Erase elements < 70
    // setCopy.erase(setCopy.begin(), setCopy.find(77));

    // setCopy.erase(77);

    // cout << "\nErase elements < 77" << endl;
    // for (auto i = setCopy.begin(); i != setCopy.end(); i++)
    // cout << *i << "\t";

    auto upper = s.upper_bound(3);
    auto lower = s.lower_bound(3);

    cout << *upper << "\t" << *lower << "\t";

    return 0;
}