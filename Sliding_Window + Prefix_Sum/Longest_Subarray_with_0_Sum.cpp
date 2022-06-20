
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :  O(log n)    but unordered SET is O(1)
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

// https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

//  brute Force  -  all the subarray find.
//  Time Complexity :  O(n ^ 2)
//  Space Complexity :  O(1)
int BruteForce(vector<int> &arr)
{
    int mex = 0, len = arr.size();

    for (int i = 0; i < len; ++i)
    {
        int sum = 0;
        for (int j = i; j < len; ++j)
        {
            sum += a[j];
            if (sum == 0)
                max = Math.max(max, j - i + 1);
        }
    }

    return max;
}

//  Time Complexity :  O(n)
//  Space Complexity :  O(n)
int LongestSubsetWithZeroSum(vector<int> arr)
{ // Prefix Sum Concept
    unordered_map<int, int> hashMap;
    int len = arr.size(), sum = 0, maxi = 0;

    for (int i = 0; i < len; i++)
    {
        sum = sum + arr[i];

        if (sum == 0)
            maxi = i + 1; //  means the subarray len will be from the beginning

        if (hashMap.find(sum) != hashMap.end()) // found
            maxi = max(maxi, i - hashMap[sum]);
        else
            hashMap[sum] = i; // ( prefixSum , index)
    }

    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr{1, 3, -1, 4, -4};

    int result = LongestSubsetWithZeroSum(arr);
    cout << "Length of the Longest Subarray with 0 sum is : " << result << endl;

    return 0;
}
