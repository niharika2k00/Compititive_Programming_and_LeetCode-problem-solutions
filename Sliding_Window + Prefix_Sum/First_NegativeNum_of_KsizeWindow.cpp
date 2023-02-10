/*
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
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

    // Print the first negative number of every window of K size.
    vector<long long> printFirstNegativeInteger(long long int arr[], long long int len, long long int k)
    {
        long long int i = 0, j = 0;
        vector<long long> res;
        deque<long long> negList;

        while (j < len)
        {

            if (arr[j] < 0)
                negList.push_back(arr[j]);

            if (j - i + 1 < k) // for 1st window when windowSize < k
                j++;

            else if (j - i + 1 == k)
            {
                if (negList.size() == 0)
                    res.push_back(0);

                else
                {
                    res.push_back(negList.front());

                    if (arr[i] == negList.front()) // 1st ele of window remove if neg
                        negList.pop_front();
                }

                i++;
                j++;
            }
        }

        return res;
    }
