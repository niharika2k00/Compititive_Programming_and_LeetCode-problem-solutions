/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/problems/find-original-array-from-doubled-array/  
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

    unordered_map<int, int> hashMap;
    vector<int> changed{1, 3, 4, 2, 6, 8};
    vector<int> answer;
    int i, len;

    len = changed.size();

    // Size Check
    if (len & 1)
    {
        cout << " { }   empty array returned ..." << endl;
        return 0;
    }

    // Hash Map Initialization
    for (i = 0; i < len; i++)
        hashMap[changed[i]]++;

    sort(changed.begin(), changed.end());

    for (i = 0; i < len; i++)
    {
        int twice = changed[i] * 2;

        if (hashMap[changed[i]] == 0)
            continue; // skips 1 iteration

        if (hashMap[twice] == 0)
        {
            cout << " { }   empty array returned ..." << endl;
            return 0;
        }

        hashMap[twice]--;
        hashMap[changed[i]]--;
        answer.push_back(changed[i]);
    }

    for (auto it : answer)
        cout << it << "\t";

    return 0;
}