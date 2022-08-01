
/*
________________________________________
  - By Niharika Dutta
 Code Link : https://www.geeksforgeeks.org/maximum-distinct-elements-removing-k-elements/
________________________________________
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

//  Time Complexity :  O(k*logd)
//  Space Complexity :  O(n)
int countDistinctElements(vector<int> &vec, int len, int k)
{
    multiset<int> multiSet;

    for (int i = 0; i < len; i++)
    {
        if (multiSet.find(vec[i]) != multiSet.end() || k != 0) // if already present means duplicate, then remove it.
            k--;

        else
            multiSet.insert(vec[i]);
    }

    if (k != 0)
        return (multiSet.size() - k);

    else
    {
        set<int> st;
        for (auto it : multiSet)
            st.insert(it);

        return st.size();
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{5, 7, 5, 5, 1, 2, 2};
    int len = vec.size(), k = 3;

    int res = countDistinctElements(vec, len, k);

    cout << "Maximum Distinct elements after K removal : " << res << endl;

    return 0;
}