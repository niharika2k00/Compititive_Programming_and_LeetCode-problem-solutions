/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3976/  
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

    //  return the length of a MAXIMUM SIZE turbulent subarray of arr.

    // https: //leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3976/discuss/1474564/Straight-forward-solution-O(n)-time-O(1)-space

    vector<int> arr{4, 8, 12, 16};
    int i, ans = 0;

    int currTrendLength = 1, maxTrendLength = 1;
    bool small = true;
    for (i = 0; i < arr.size() - 1; i++)
    {
        // if (arr[i] == arr[i + 1])
        // {
        //     currTrendLength = 1;
        //     continue;
        // }
        currTrendLength = small != arr[i] < arr[i + 1] ? currTrendLength + 1 : 2;
        small = arr[i] < arr[i + 1];
        maxTrendLength = max(maxTrendLength, currTrendLength);
    }

    cout << maxTrendLength << endl;

    return 0;
}