
//   LINKS ::  https://leetcode.com/contest/biweekly-contest-58/problems/check-if-move-is-legal/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

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

    return 0;
}

//  ____   FUNCTION _____
bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
{

    int dX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    char oppositeColor;
    if (color == 'W')
        oppositeColor = 'B';
    else
        oppositeColor = 'W';

    int i, x, y;

    for (i = 0; i < 8; i++)
    {
        //           denotes the cellls in that direction
        x = dX[i] + rMove;
        y = dY[i] + cMove;

        if (x >= 0 && x < 8 && y >= 0 && y < 8)
        {
            if (board[x][y] == oppositeColor)
            {
                while (1)
                {
                    x = dX[i] + rMove;
                    y = dY[i] + cMove;

                    if (x < 0 || y < 0 || x >= 8 || y >= 8)
                        break;
                    if (board[x][y] == color)
                        return true;
                    if (board[x][y] == '.') //  if an empty cell exsist
                        break;
                }
            }
        }
    }

    return false;
}