/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

              https://leetcode.com/problems/longest-substring-without-repeating-characters/
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

void longestSubstringWithoutRepeatingCharacters(string s)
{
    int i, start = 0, end = 0, maxLength = 0, temp = 0, windowSize;
    unordered_map<char, int> map;

    for (end = 0; end < s.size(); end++)
    {
        map[s[end]]++;
        // cout << "Size of map = " << map.size() << endl;
        windowSize = end - start + 1;

        if (map.size() == windowSize)
            maxLength = max(maxLength, windowSize);

        else if (map.size() < windowSize)
        {
            while (map.size() < windowSize)
            {
                map[s[start]]--;

                if (map[s[start]] == 0)
                    map.erase(s[start]);

                start++;
                windowSize = end - start + 1;
            }
        }
    }

    cout << " Max Length Substring Without Repeating Characters : " << maxLength << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "aabbacd"; //  pwwekw  -->  3
    longestSubstringWithoutRepeatingCharacters(s);

    return 0;
}