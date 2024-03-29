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

//  Time Complexity :  O(n ^ 2)
int BruteForceApproach(string s)
{
    int len = s.size(), maxLength = 0;

    for (int i = 0; i < len; i++)
    {
        vector<bool> visited(256, false);
        for (int j = i; j < len; j++)
        {
            if (visited[s[j]] == true) // already exsist
                break;

            else
            {
                visited[s[j]] = true;
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

//  Time Complexity :  O(n +  d)
//   Means Longest Substring With Unique Characters
void longestSubstringWithoutRepeatingCharacters(string s)
{
    int start = 0, end = 0, maxLen = -1, windowSize = 0;
    unordered_map<char, int> map;

    for (end = 0; end < s.size(); end++)
    {
        map[s[end]]++;
        // cout << "Size of map = " << map.size() << endl;
        windowSize = end - start + 1;

        if (map.size() == windowSize) // all unique
            maxLength = max(maxLength, windowSize);

        else if (map.size() < windowSize) // repeated elements
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

    string s = "pwwekw"; //  pwwekw  -->  3

    cout << " Max Length Substring Without Repeating Characters : " << BruteForceApproach(s) << endl;
    // longestSubstringWithoutRepeatingCharacters(s);

    return 0;
}