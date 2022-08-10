/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :
 Time Complexity :  O(n^2)
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

void BubbleSort(int arr[], int len) // OR  int *arr        pass by reference
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                count++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Number of swaps => " << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {5, 1, 4, 2, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, len);

    for (auto ele : arr)
        cout << ele << "\t";

    return 0;
}

/*
         Number of Swaps in Bubble Sort  ==  Inversion Sort

            means in [5 1 4 2 8], the INVERSION PAIRS are --->   4
                (5 1) , (5 4) , (5 2) , (4 2)
 */

sudo - s whoami

            //  Password Reset
            sudo passwd root

                //  Create New User
                sudo adduser<username>

                    passwd niharika

                        // Login as a Non - Root User
                        sudo su -
        root
            sudo su -
        niharika

            // WSL
            In Power
            Shell(Run as administrator)
                wsl
        - l - v <
    --to check the version

    select name,
    language, forks_count, stargazers_count from github_my_repository;

steampipe query "select name from steampipe_registry_plugin;"
