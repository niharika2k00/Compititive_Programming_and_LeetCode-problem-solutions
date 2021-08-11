/* 
________________________________________
  - By Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
________________________________________
 */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

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

void minimumCostRopes(int vec[], int len)
{
    int sum = 0, ele1, ele2;
    // Using MIN HEAP
    priority_queue<int, vector<int>, greater<int>> pq(vec, vec + len); // initialises all the elements of the array

    while (pq.size() > 1)
    {
        ele1 = pq.top();
        pq.pop();
        ele2 = pq.top();
        pq.pop();
        sum = sum + (ele1 + ele2);
        pq.push(ele1 + ele2);
    }

    cout << "Minimum cost of connecting N Ropes : " << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vec[] = {4, 1, 6, 18, 10};
    int len = sizeof(vec) / sizeof(vec[0]);

    minimumCostRopes(vec, len);

    return 0;
}