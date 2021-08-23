/* 
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/  
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

    vector<int> vec = {2, 10, -4, 69, 20, 8};
    deque<int> Q;
    int i = 0, k = 3;

    for (i = 0; i < k; i++)
    { // if the current element is GREATER than the previously inserted element ? Pop Q.back()
        while (!Q.empty() && vec[i] >= vec[Q.back()])
            Q.pop_front();
        Q.push_back(i); // index store
    }

    for (i = k; i < vec.size(); i++)
    {
        cout << Q.front() << "\t";

        // pop() element from the Front which lie outside the Window.
        while (!Q.empty() && Q.front() <= i - k)
            Q.pop_front();

        while (!Q.empty() && vec[i] >= vec[Q.back()])
            Q.pop_front();
        Q.push_back(i);
    }

    // print the max ele of the Last Window
    cout << vec[Q.front()];

    return 0;
}