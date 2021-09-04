/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/contest/biweekly-contest-60/problems/find-the-middle-index-in-array/  
 Time Complexity :  
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

int findElement(int arr[], int n)
{
    if (n == 1)
        return 0;

    vector<int> prefix(n, 0), suffix(n, 0);
    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        int bf = (i == 0) ? 0 : prefix[i - 1];
        int af = (i == n - 1) ? 0 : suffix[i + 1];
        if (bf == af)
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {1, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findElement(arr, n);

    return 0;
}

/* 
TEST CASES :: 

[0 0 0 0]
ans : 0

[0 4]
ans : 1 

[1 -1 4]
ans : 2 

[2 3 -1 8 4]
ans : 3
 */

/* 
        
        if(nums.size()==1) return 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int rr = 0;
        
        int pp=-1;
        
        for(int i=nums.size()-1; i>=0 ; i--){
            if(rr == sum - (nums[i]+rr))
                pp = i;
            
            rr+=nums[i];
        }
        
        return pp;
    }

 */