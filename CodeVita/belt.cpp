
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

void helperConversion(vector<string> &vec, vector<vector<string>> grid, lli n, lli m)
{
    for (lli i = 0; i < m; i++)
    {
        if (i & 1)
        {
            for (lli j = n - 1; j >= 0; j--)
                vec.push_back(grid[i][j]);
        }
        else
        {
            for (lli j = 0; j < n; j++)
                vec.push_back(grid[i][j]);
        }
    }
}

//  Helper function
vector<string> manupulateString(vector<string> vec, lli storage, lli m, lli n)
{
    storage = storage % (m * n);
    lli i = m * n - storage, j = m * n - 1;

    while (i < j)
        swap(vec[i++], vec[j--]);

    i = 0, j = m * n - storage - 1;

    while (i < j)
        swap(vec[i++], vec[j--]);

    i = 0, j = m * n - 1;

    while (i < j)
        swap(vec[i++], vec[j--]);

    return vec;
}

//  Matrix Display Functions
pair<lli, lli> displayMatrix(vector<string> vec, lli n, lli m, string str)
{
    pair<lli, lli> ResultPair = {-1, -1};
    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < n; j++)
        {
            lli index = i * n + (i & 1 ? n - 1 - j : j);
            if (vec[index] == str)
            {
                ResultPair.first = (index / n);
                ResultPair.second = (i & 1) ? n - 1 - index % n : (index % n);
            }
            cout << vec[index] << ' ';
        }
        cout << '\n';
    }

    return ResultPair;
}

void solve()
{
    lli m, n, storage;
    cin >> m >> n;

    string str;
    vector<string> vec;
    vector<vector<string>> grid(m, vector<string>(n));

    for (lli i = 0; i < m; i++)
        for (lli j = 0; j < n; j++)
            cin >> grid[i][j];

    cin >> storage >> str;

    helperConversion(vec, grid, n, m);

    vec = manupulateString(vec, storage, m, n);

    pair<lli, lli> ResultPair = {-1, -1};
    ResultPair = displayMatrix(vec, n, m, str);

    if (ResultPair.second == -1 && ResultPair.first == -1)
        cout << "Not Available";
    else
        cout << '[' << ResultPair.first << ", " << ResultPair.second << ']';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
