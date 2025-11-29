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

    vector<int> nums{1, 5, 3, 4, 2};
    int k = 3, i, count = 0, len = nums.size(), j = 0;

    // ----------------------------
    // ==  BRUTE FORCE  O(n^2)  ==
    // ----------------------------

    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
            if (abs(nums[i] - nums[j]) == k || abs(nums[j] - nums[i]) == k)
                count++;
    }

    // ----------------------------
    //     HASH - MAP APPROACH   O(n)
    // ----------------------------
    /*
            ::   ALGORITHM   ::
        1) Store elements in a HashMap
        2) DON'T USE THE DUPLICATE ELEMENT, thus instead of iterating through the Array we are iterating the HASHMAP as it contains Unique Ele
        3) Check HashMap.find()      || OR ||     HashMap.count() exsist or not.
     */

    unordered_map<int, int> HashMap;
    for (i = 0; i < len; i++)
        HashMap[nums[i]]++;

    for (auto it : HashMap)
        if (HashMap.find(it.first + k) != HashMap.end()) //  OR    if (HashMap.count(it.first + k))
            count++;

    // ----------------------------
    // == TWO POINTERS APPROACH ==
    // ----------------------------

    int left = 0, right = len - 1;
    sort(nums.begin(), nums.end());
    while (right >= left)
    {
        if (nums[right] - nums[left] == k)
        {
            // count++;
            left++;
            right--;
        }
        else if (nums[right] - nums[left] > k) //  Diff Greater
            right--;
        else
            left++;
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
