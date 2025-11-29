
/*
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define NO_OF_CHARS 256
#define mp make_pair
#define loop1(n) for (ll i = 0; i < (n); i++)
#define loop2(n) for (ll i = 1; i <= (n); i++)
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

// Time Complexity :  O(nlogn)
bool anagram_usingSorting(string s1, string s2)
{
    /*
    value > 0 : s1[0] > s2[0]
    value < 0 : s1[1] < s2[0]
     */
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1.compare(s2) < 0 || s1.compare(s2) > 0)
        return false;
    else
        return true;
}

// Time Complexity :  O(n)
bool anagram_usingCountCharacter(string s1, string s2)
{
    vector<int> vecCount(NO_OF_CHARS, 0);
    // int vecCount[NO_OF_CHARS] = {0};
    int i;

    if (s1.length() != s2.length())
        return false;

    for (i = 0; i < s1.length(); i++)
    {
        vecCount[s1[i]]++;
        vecCount[s2[i]]--;
    }

    for (i = 0; i < NO_OF_CHARS; i++)
        if (vecCount[i]) // !0
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1 = "LISTEN", s2 = "SILENT";
    int i = 0;

    bool result = anagram_usingSorting(s1, s2);
    bool result = anagram_usingCountCharacter(s1, s2);

    if (result)
        cout << "Yes both are Anagrams" << endl;
    else
        cout << "Not Anagrams" << endl;

    return 0;
}
