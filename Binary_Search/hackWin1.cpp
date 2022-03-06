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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    set<int> arr2Set;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr2[i] = x;
        arr2Set.insert(x);
    }
    unordered_set<int> s;
    for (int data1 : arr1)
    {
        for (int data2 : arr2)
        {
            s.insert(data1 ^ data2);
        }
    }
    int xorValue = -1;
    for (int data1 : s)
    {
        int x = 0;
        for (int data2 : arr1)
        {
            if (arr2Set.find(data1 ^ data2) != arr2Set.end())
                x++;
        }
        if (x == n)
        {
            xorValue = data1;
            break;
        }
    }
    vector<int> ans;
    if (xorValue != -1)
    {
        for (int data : arr1)
        {
            ans.push_back(data ^ xorValue);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ans.push_back(-1);
        }
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