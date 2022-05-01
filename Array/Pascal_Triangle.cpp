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

void printPascal(int rows)
{
    int coef = 1;

    for (int i = 0; i < rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
            cout << "  ";

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            cout << coef << "   ";
        }
        cout << endl;
    }
}

//  Find the element at ROW 5 and Col 3
/*
     Formula :
     n C r  = (row -1) C (Col - 1)  =  4 C 2 =   4! / 2! * 2! = 4 * 3 * 2! / 2! * 2! =  6 ans
*/

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void findElement(int row, int col)
{
    int res = 0;
    res = factorial(row - 1) / (factorial(col - 1) * factorial(row - col));

    cout << "Element at Row " << row << " and Column " << col << " is   --->  " << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5, row = 5, col = 3;
    printPascal(n);

    // cout << "Enter row : ";
    // cin >> row;
    // cout << "Enter column : ";
    // cin >> col;

    findElement(row, col);

    return 0;
}