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

int Subsequence_With_SumK(vector<int> &vec, int K, int len, int index, int sum)
{
    int right, left;
    if (index == len)
    {
        if (sum == K)
            return 1;
        return 0;
    }

    right = Subsequence_With_SumK(vec, K, len, index + 1, sum + vec[index]);
    left = Subsequence_With_SumK(vec, K, len, index + 1, sum); //  Not Take / Include

    return (right + left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{1, 2, 1};

    int K = 2, len = vec.size();
    cout << "Len = " << len << endl;
    cout << "Total number of Subsequences with Given Sum  =  " << Subsequence_With_SumK(vec, K, len, 0, 0) << endl;

    return 0;
}
