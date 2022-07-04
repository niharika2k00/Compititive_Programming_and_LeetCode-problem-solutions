/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/allocate-minimum-number-pages/  
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

bool isPossible(int arr[], int size, int m, int mid)
{
    int studentsRequired = 1, i, curr_sum = 0;
    // iterate over all books
    for (i = 0; i < size; i++)
    {
        if (arr[i] > mid) // if yes means move Right to the MiD
            return false;

        if (curr_sum + arr[i] > mid) //  students are required to distribute mid pages
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

int findMinimumPages(int arr[], int size, int m)
{
    int start, end, i, ans = INT_MAX, sum = 0, mid;
    for (i = 0; i < size; i++)
        sum = sum + arr[i];

    start = 0;
    end = sum;

    if (m > size)
        return -1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (isPossible(arr, size, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {10, 20, 30, 40}, size = sizeof(arr) / sizeof(arr[0]), m = 2; // m --> No. of students

    cout << "Minimum number of pages = " << findMinimumPages(arr, size, m) << endl;

    return 0;
}