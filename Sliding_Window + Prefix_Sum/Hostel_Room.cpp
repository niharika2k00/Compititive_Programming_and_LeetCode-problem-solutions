/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codechef.com/START26C/problems/HOSTELROOM
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

/*
     It is guaranteed in the input that at any moment of time, the number of people in the room does not become negative.
           Then Rollback to the Previous MAX
 */
void solve()
{
    int len, people, i, maxPeople = 0, store = 0;
    cin >> len >> people;
    store = people;
    vector<int> vec(len);
    for (i = 0; i < len; i++)
        cin >> vec[i];

    for (i = 0; i < len; i++)
    {
        if (vec[i] >= 0)
        {
            people = people + vec[i];
            store = people;
        }
        else
        {
            people = people - abs(vec[i]);

            if (people < 0)
                break;
        }
        maxPeople = max(maxPeople, store);
    }

    cout << maxPeople << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        solve();
    }

    return 0;
}