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
    int k = 1, i, count = 0, left = 0, right = 0, len = nums.size(), j = 0;

    /*     sort(nums.begin(), nums.end());
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
    } */

    // Pick all elements one by one
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
            if (abs(nums[i] - nums[j]) == k || abs(nums[j] - nums[i]) == k)
                count++;
    }

    cout << count << endl;

    return 0;
}

/* 
              EXPLANATIONS ::

    Sort the array 
    Take two pointers, l, and r, both pointing to 1st element
    Take the difference arr[r] – arr[l]
    If value diff is K, increment count and move both pointers to next element
    if value diff > k, move l to next element
    if value diff < k, move r to next element
        return count

 */