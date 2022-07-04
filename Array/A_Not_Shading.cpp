/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://codeforces.com/contest/1627/problem/A
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

int Helper(vector<vector<char>> &vec, int targetRow, int targetCol, int row, int col)
{
    // Initialisation
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> vec[i][j];

    bool containBlack = false;

    if (vec[targetRow][targetCol] == 'B')
        return 0;

    else
    {
        // Search target entire row
        for (int i = 0; i < col; i++)
            if (vec[targetRow][i] == 'B')
                return 1;

        // Search target entire col
        for (int i = 0; i < row; i++)
            if (vec[i][targetCol] == 'B')
                return 1;

        // No Cell Black  --> -1
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (vec[i][j] == 'B')
                {
                    containBlack = true;
                    break;
                }

        if (!containBlack)
            return -1;
    }
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        int row, col, targetRow, targetCol;
        cin >> row >> col >> targetRow >> targetCol;
        vector<vector<char>> vec(row, vector<char>(col));
        // char vec[row][col];

        targetRow = targetRow - 1;
        targetCol = targetCol - 1;

        cout << Helper(vec, targetRow, targetCol, row, col) << endl;
    }
    return 0;
}
