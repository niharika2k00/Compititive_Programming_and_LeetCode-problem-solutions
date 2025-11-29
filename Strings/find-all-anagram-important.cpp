/*
________________________________________
----------------------------------------
 Author :  Niharika Dutta
 Code Link :
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

    // SLIDING WINDOW TECHNIQUE
    //  take window size as the size of the small string

    string str = "abcdebacb";
    string pattern = "cab";
    int i, patternLen = pattern.size(), strLen = str.size();
    int window = patternLen;
    vector<int> freqA(26, 0), freqStr(26, 0), result;

    if (pattern.size() > str.size())
        cout << "Not possible as window length is more than original string ..." << endl;

    // Frequency array
    for (i = 0; i < pattern.size(); i++)
    {
        int c1 = pattern[i] - 'a'; // pattern string (window)
        freqStr[c1]++;

        int c2 = str[i] - 'a'; // main string
        freqA[c2]++;
    }

    //  If both the frequency array matches then add 1st index in the Ans.
    if (freqA == freqStr)
        result.push_back(0);

    //  Iterator starts after the FIRST WINDOW
    //     Delete the Last Ele
    //     Add Next Ele in the NEW WINDOW
    for (i = patternLen; i < strLen; i++)
    {
        int append = str[i] - 'a';
        freqA[append]++;

        int count = str[i - window] - 'a';
        freqA[count]--;

        if (freqA == freqStr)
            result.push_back(i - window + 1);
    }

    cout << "\nStarting Index for ANAGRAM :  \n ";
    for (auto it : result)
        cout << it << "\t";
    cout << "\n\nTotal Anagrams encountered : " << result.size() << "\n";

    return 0;
}