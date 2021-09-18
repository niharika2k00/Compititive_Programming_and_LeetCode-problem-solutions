/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/contest/biweekly-contest-61/problems/count-number-of-pairs-with-absolute-difference-k/  
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

    vector<int> nums{1, 2, 2, 1};
    int k = 1, i, count = 0, left = 0, right = 0;

    sort(nums.begin(), nums.end());
    while (right < nums.size())
    {
        if (abs(nums[right] - nums[left]) == k)
        {
            count++;
            left++;
            right++;
        }
        else if (abs(nums[right] - nums[left]) > k)
            left++;
        else // nums[right] - nums[left] < sum
            right++;
    }

    cout << count << endl;

    return 0;
}