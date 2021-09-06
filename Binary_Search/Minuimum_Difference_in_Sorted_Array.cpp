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

int minimumElementDifference(int arr[], int start, int end, int key)
{
    int mid, diff1, diff2;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (key == arr[mid])
            return arr[mid];
        else if (key < arr[mid])
            end = mid - 1;
        else if (key > arr[mid]) // Right side
            start = mid + 1;
    }

    diff1 = abs(key - arr[end]);
    diff2 = abs(key - arr[start]);

    if (diff1 < diff2)
        return arr[end];
    else
        return arr[start];
}

/* 
EXPLANATION :: 

    - We can find Floor & Ceil and find the difference (But this method is quite Lenghty)

    Mehod - 2
    - Just calculate the simple binary search (BS)
              # Find the MID 
              # if key if found then return arr[mid]
              # if not found then just do end = mid -1      &      start = mid + 1 accordingly
              # AT THE LAST ITERATION IN THE WHILE LOOP EVERYTIME THE END < START  BY 1 DIFFERENCE ,  So take that start and end at the end after the 
                    Loop iteration completes                  

 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {4, 6, 10, 16}, key = 7, res = 0, size = sizeof(arr) / sizeof(arr[0]);
    res = minimumElementDifference(arr, 0, size - 1, key);
    cout << "Minimum difference with the Key : " << res << endl;

    return 0;
}