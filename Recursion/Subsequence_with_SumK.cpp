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

void Subsequence_With_SumK(vector<int> &vec, int K, int len, int index, int sum, vector<int> &temp)
{
    if (index == len)
    {
        if (sum == K)
        {
            for (auto it : temp)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    temp.push_back(vec[index]); //  Take / Include
    Subsequence_With_SumK(vec, K, len, index + 1, sum + vec[index], temp);
    temp.pop_back();
    Subsequence_With_SumK(vec, K, len, index + 1, sum, temp); //  Not Take / Include
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{1, 2, 1};
    vector<int> temp;
    int K = 2, len = vec.size();
    cout << "Len = " << len << endl;
    Subsequence_With_SumK(vec, K, len, 0, 0, temp);

    return 0;
}
