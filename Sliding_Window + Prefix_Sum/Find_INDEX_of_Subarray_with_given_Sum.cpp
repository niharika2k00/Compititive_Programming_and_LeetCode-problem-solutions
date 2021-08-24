
/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    
 Time Complexity :  O(n)        
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //   **************          THIS ALGO DOESNT DEALS WITH THE NEGATIVE ELEMENTS SO FOR THAT REFER TO METHOD 2        ***********
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, sum = 15, start = 0, currSum = 0, n = sizeof(arr) / sizeof(arr[0]), flag = 0;

    for (i = 0; i < n; i++)
    {
        while (currSum > sum && start < i)
        {
            currSum = currSum - arr[start];
            start++;
        }

        if (currSum == sum)
        {
            cout << "FOUND .... Subarray from index " << start << " to " << i - 1 << endl;
            flag = 1;
            break;
        }

        currSum = currSum + arr[i];
    }

    if (!flag)
        cout << "No subarray found";

    return 0;
}

/* 

EXPLANATIONS :: 

- Using Prefix Sum add the element one by one 

FOR LOOP START :
- (LOOP) if (currSum >  SUM)
       * Subtract element from the front of the arr using Index
       * Modify the Start Index

- if (currSum ==  SUM)
        print the start and the end Index        

- ADD currSum  = currSum + arr[i];   // prefix sum
FOR LOOP ENDS :


 */