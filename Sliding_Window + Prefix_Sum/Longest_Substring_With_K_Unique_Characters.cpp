/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link : https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/   
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

void longestSubstring_K_uniqueCharacters(string s, int k)
{
    unordered_map<char, int> map; // all index of map is initialised with 0 by default
    int end = 0, i = 0, maxLenghtSubstring = 0;

    for (end = 0; end < s.size(); end++)
    {
        map[s[end]]++;
        cout << "Size of map = " << map.size() << endl;

        if (map.size() == k)
            maxLenghtSubstring = max(maxLenghtSubstring, end - i + 1);

        else if (map.size() > k)
        {
            int in = i;
            while (map[s[in]] != 0)
            {
                map[s[i]]--;
                i++;
            }
            auto a = map.find(s[in]);
            map.erase(a);
        }
    }

    cout << " Size = " << maxLenghtSubstring << "\t Substring =  " << s.substr(i, end) << endl;
    ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "aabacbebebe";
    int k = 3;
    longestSubstring_K_uniqueCharacters(s, k);

    return 0;
}