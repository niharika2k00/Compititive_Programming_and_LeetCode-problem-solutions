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

void removeHandler(string s, int len)
{
    int count = 0, flag = 1, store = 0, first = 0;
    unordered_map<char, int> hashMap;
    set<char> set;
    vector<int> freq;

    //  Stores the frequency of the string
    for (int i = 0; i < len; i++)
        hashMap[s[i]]++;

    for (auto it : hashMap)
        set.insert(it.second);

    cout << "Set size : " << set.size() << endl;
    int setSize = set.size();

    //  all have same frequency
    if (setSize == 1)
        cout << "VALID STRING" << endl;

    else if (setSize > 2)
        cout << "INVALID STRING" << endl;

    else if (setSize == 2)
    {
        for (auto it : hashMap)
            freq.push_back(it.second);

        sort(freq.begin(), freq.end());

        int start = freq[0];
        for (int i = 1; i < freq.size(); i++)
        {
            int diff = abs(freq[i] - start);
            if (diff == 1 && flag == 1)
                count++;
        }

        unordered_map<int, int> freqMap;

        for (int i = 0; i < freq.size(); i++)
            freqMap[freq[i]]++;

        for (auto it : freqMap)
        {
            first = it.second;

            if (flag)
            {
                store = first; // 2
                flag = 0;
            }
        }

        int res = abs(first - store);

        if (count > 1)
            cout << "\nINVALID STRING" << endl;

        if (res == 1)
            cout << "\nVALID STRING" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "dddaaacbbbddbaab";
    int len = s.size();

    removeHandler(s, len);

    return 0;
}