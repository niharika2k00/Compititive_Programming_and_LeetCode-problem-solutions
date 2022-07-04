// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n)       \
    for (ll i = 0; i < n; i++) \
        cin >> arr[i];
#define printarr(arr, n)       \
    for (ll i = 0; i < n; i++) \
        cout << arr[i] << ' ';

/*
  Given 2 arrays num1 & num2, find an array C[n]  forming on reordering of num2 such that -
      num1[0] xor C[0] ==  num1[1] xor C[1]  ==   num1[2] xor C[2] ==  ..........  ==   num1[n-1] xor C[n-1].

      If it satisfies then return arr C (modification of num2) else return arr[n] size n having -1 as each element.


      Test Case ::
                    1) Input :                     Output : -1 -1 -1
                       3
                       2 2 5
                       5 0 0

                    2) Input :                      Output : 1 13 4
                        3
                        2 14 7
                        13 4 1

                    3) Input :                      Output : 1 7 10 0 6
                        5
                        3 5 8 2 4
                        10 0 6 7 1
*/

void solve()
{
    int len;
    cin >> len;
    vector<int> arr1(len);
    vector<int> arr2(len);
    set<int> arr2Set;
    for (int i = 0; i < len; i++)
        cin >> arr1[i];
    for (int i = 0; i < len; i++)
    {
        int x;
        cin >> x;
        arr2[i] = x;
        arr2Set.insert(x);
    }

    unordered_set<int> Set;
    for (int data1 : arr1)
    {
        for (int data2 : arr2)
            Set.insert(data1 ^ data2); // stores all xor results
    }

    int xorValue = -1;
    for (int data1 : Set)
    {
        int x = 0;
        for (int data2 : arr1)
            if (arr2Set.find(data1 ^ data2) != arr2Set.end())
                x++;

        if (x == len) // means all XOR values exist in the num2
        {
            xorValue = data1;
            break;
        }
    }

    vector<int> ans;
    if (xorValue == -1)
    {
        for (int i = 0; i < len; i++)
            ans.push_back(-1);
    }
    else
    {
        for (int data : arr1)
            ans.push_back(data ^ xorValue);
    }
    printarr(ans, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}