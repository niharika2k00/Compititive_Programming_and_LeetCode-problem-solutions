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

void Subsequences(vector<int> &vec, int len, int index, vector<int> &temp)
{
    // Means reaches END of the subtree
    if (len == index)
    {
        if (temp.size() == 0)
            cout << "{ }";

        else
            for (auto it : temp)
                cout << it << " ";

        cout << endl;
        return;
    }

    temp.push_back(vec[index]);
    Subsequences(vec, len, index + 1, temp);

    // Backtracking Step
    temp.pop_back();
    Subsequences(vec, len, index + 1, temp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{3, 2};
    int len = vec.size();
    vector<int> temp;

    Subsequences(vec, len, 0, temp);
    return 0;
}