/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link : https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/

             https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
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

//  Time Complexity :  O(n ^ 2)
//   BruteForce Approach    TLE
int BruteForce(string s, int k)
{
    int len = s.size(), maxLen = -1;

    for (int i = 0; i < len; i++)
    {
        unordered_map<char, int> hashMap;

        for (int j = i; j < len; j++)
        {
            hashMap[s[j]]++;

            if (hashMap.size() == k)
                maxLen = max(maxLen, j - i + 1);

            if (hashMap.size() > k)
                break;
        }
    }

    return maxLen;
}

void longestSubstring_K_uniqueCharacters(string s, int k)
{
    unordered_map<char, int> map; // all index of map is initialised with 0 by default
    int end = 0, i = 0, maxLenghtSubstring = -1;

    for (end = 0; end < s.size(); end++)
    {
        map[s[end]]++;
        // cout << "Size of map = " << map.size() << endl;

        if (map.size() == k)
            maxLenghtSubstring = max(maxLenghtSubstring, end - i + 1);

        else if (map.size() > k)
        {
            //  Remove elements from the start of the Window so that the size of map decreases by 1.
            while (map.size() > k)
            {
                map[s[i]]--;
                if (map[s[i]] == 0)
                    map.erase(s[i]);
                i++;
            }
        }
    }

    cout << " Size = " << maxLenghtSubstring << "\t Substring =  " << s.substr(i, end) << endl;
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

/*
    ALGORITHM ::

  1) start = 0 , end = 0 ,  maxLenghtSubstring = -1

  2)  if (mp.size() == k)   UPDATE maxLen
         MAX of [ maxLenghtSubstring  OR end -  start + 1]

  3) if (mp.size() > k)
                // when unique characters means map.size() exceeds K as map contains the count of the unique ele.
                // Remove one element from the start (BEGINNING) , shift i(start)
                // map[s[start]] -- ;    means -1 from the Count
                // Increament start
 */