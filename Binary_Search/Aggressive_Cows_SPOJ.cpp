/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.spoj.com/problems/AGGRCOW/  
              https://www.youtube.com/watch?v=wSOfYesTBRk&list=PLgUwDviBIf0qYbL4TBaEWgb-ljVdhkM7R&index=9 
 
 Time Complexity :   O (n log n)
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

bool canPlaceCow(int stall[], int cows, int mid, int size)
{
    int cowPlaced = stall[0], count = 1, i;

    for (i = 1; i < size; i++)
    {
        if ((stall[i] - cowPlaced) >= mid) // If difference between the stalls of placed cows is more or === mid then OK ,continue
        {
            count++;
            cowPlaced = stall[i];
        }
        if (count == cows)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int stall[] = {1, 2, 8, 4, 9}, size = sizeof(stall) / sizeof(stall[0]), mid, i, cows = 3, start, end, ans = 0;

    sort(stall, stall + size);
    start = 0;
    end = stall[size - 1] - stall[0];

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (canPlaceCow(stall, cows, mid, size))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << "\n Largest Minimum distance between the Cows Placed : " << ans << endl;

    return 0;
}