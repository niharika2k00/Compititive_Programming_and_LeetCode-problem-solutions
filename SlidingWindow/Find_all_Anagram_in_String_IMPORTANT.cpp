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

    string A = "abcdebacb";
    string str = "cab";
    int i, windowLength = str.size(), Alength = A.size();
    vector<int> freqA(26, 0), freqStr(26, 0), result;

    if (str.size() > A.size())
        cout << "Not possible as window length is more than original string ..." << endl;

    // frequency array
    for (i = 0; i < str.size(); i++)
    {
        int c1 = str[i] - 'a'; // small string (window)
        freqStr[c1]++;

        int c2 = A[i] - 'a'; // latge string
        freqA[c2]++;
    }

    //  If both the frequency array matches then add 1st index in the Ans.
    if (freqA == freqStr)
        result.push_back(0);

    int end = str.size(); // 3
    for (i = 0; i + windowLength < Alength; i++)
    {
        int count = A[i] - 'a';
        freqA[count]--;

        int append = A[end] - 'a';
        freqA[append]++;

        end++;

        if (freqA == freqStr)
            result.push_back(i);
    }

    cout << "\nStarting Index for ANAGRAM :  \n ";
    for (i = 0; i < result.size(); i++)
        cout << result[i] << "\t";

    return 0;
}