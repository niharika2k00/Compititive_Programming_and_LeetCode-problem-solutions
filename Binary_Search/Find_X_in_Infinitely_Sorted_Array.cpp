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

int findingEnd(int arr[], int start, int end, int key)
{
    int mid;
    // Loop Terminates when the KEY lies between start & end. ----> key < arr[end]  terminate
    while (key > arr[end])
    {
        start = end;
        end = end * 2;
    }
    return end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170}, key = 10, end = 0, result = 0, size = sizeof(arr) / sizeof(arr[0]);
    end = findingEnd(arr, 0, 1, key);

    // After we get the end index then assume that it is a finite array. So use normal Binary Search. here ihave used STL inbuild one .
    result = binary_search(arr, arr + end, key);
    cout << end << endl;

    return 0;
}