/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://codeforces.com/contest/1579/problem/D  
 Time Complexity :  
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        ll i, n;
        cin >> n;
        priority_queue<pair<ll, ll>> pq;
        vector<pair<ll, ll>> ans;
        vector<ll> sociability(n);

        // Input Sociability Array
        for (i = 0; i < n; i++)
        {
            cin >> sociability[i];
            if (sociability[i] > 0)
                pq.push(make_pair(sociability[i], i + 1));
        }

        while (pq.size() >= 2)
        {
            // 2 person
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            // sociability decreases by 1 after 1 talk
            p1.first--;
            p2.first--;

            ans.push_back(make_pair(p1.second, p2.second));

            // if sociability > 0 ,then PUSH
            if (p1.first > 0)
                pq.push(p1);
            if (p2.first > 0)
                pq.push(p2);
        }

        cout << ans.size() << endl;
        for (auto it : ans)
            cout << it.first << " " << it.second << endl;
    }

    return 0;
}

/* 
                      EXPLANATIONS 
                  ______________________

        1) Take MAX HEAP -----> so that the person having MAX sociability will appear on the top
        2) then pop() top 2 persons 
        3) Decrease their sociability by 1
        4) Make_Pair of these 2 persons and PUSH into the answer array
        5) then again push into the PRIORITY_QUEUE if sociability > 0              

                         Print the answer array.
 */