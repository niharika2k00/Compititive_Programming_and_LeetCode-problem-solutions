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

int numOfDigit(int num)
{
    int count = 0;
    while (num > 0)
    {
        num = num / 10;
        count++;
    }

    return count;
}

int allOdd(int num)
{
    int digi = 0;
    while (num > 0)
    {
        digi = num % 10;   // extract last digit
        if (digi % 2 == 0) //  even
            return 0;

        num = num / 10;
    }

    return 1; //  means all Odd
}

void solve()
{
    int len = 0, i, totalCost = 0, num = 0, cost = 0;
    cin >> len;
    vector<int> vec(len);
    for (i = 0; i < len; i++)
        cin >> vec[i];

    cout << "LEN " << len << endl;

    if (len == 1 && vec[0] % 2 == 0) // 1 ele & Even
    {
        cout << 0 << endl;
        return;
    }

    for (i = 0; i < len; i++)
    {
        num = vec[i], cost = 0;
        int isFullOdd = allOdd(num);

        if (isFullOdd) // like 55 , 135
            cost = -1;

        else if (num >= 0 && num <= 9 && num % 2 != 0) // single digit and Odd
            cost = 1;

        else if ((num % 10) % 2 == 0) //  Unit digit checking if Even
            cost = 0;

        else
        {
            int numLen = numOfDigit(num), digi;
            numLen = numLen - 1;
            int i = numLen;

            while (num > 0)
            {
                digi = num % 10;
                if (digi % 2 == 0) //  even
                {
                    cost = numLen - i;
                    break;
                }

                i--;
                num = num / 10;
            }
        }

        totalCost = totalCost + cost;
    }

    cout << totalCost << endl;
}

/*
    Question ::  For an integer N, you can perform the following operations any number of times.
                  Choose any 2 ADJACENT NUMBER and Swap.
               The Cost of any integer is defined as the Minimum Number of operations to make the number EVEN   ans   -1 if NOT POSSIBLE.

               Find the Sum of Costs of all integers in the given queries.


    Input ::  vector of number

    TestCase ::
                  1) Input : 2  =>  Output : 0
                  2) Input : vector len(5)
                              21    --->  1 (no. of Swaps)
                              3     --->  -1
                              431   --->  swap 4 & 3 then 341 then again swap 1 & 4 then becomes 314 hence EVEN.  + 1
                              41    --->  1
                              55    --->  -1

                     Therefore, Cost = add all = (1 - 1 + 1)

 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}