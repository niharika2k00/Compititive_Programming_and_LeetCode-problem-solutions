/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
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

int SubsetCounter(vector<vector<int>> &Dp, vector<int> &vec, int sum, int len) // SAME AS void fun(int *arr)
{
    int consider, notConsider;
    if (len == 0 && sum == 0)
        return 1;

    if (len == 0 && sum != 0)
        return 0;

    if (Dp[len][sum] != 0)
        return Dp[len][sum];

    // When arr Element is Greater than SUM .
    if (vec[len - 1] > sum)
        return Dp[len][sum] = SubsetCounter(Dp, vec, sum, len - 1); //  Not Consider

    consider = SubsetCounter(Dp, vec, sum - vec[len - 1], len - 1); //  Consider
    notConsider = SubsetCounter(Dp, vec, sum, len - 1);             // Not Consider

    return Dp[len][sum] = consider + notConsider;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec{1, 1, 2, 3};
    int diff = 1, len = vec.size(), count = 0, totalSum = accumulate(vec.begin(), vec.end(), 0);
    int subset1Sum = (diff + totalSum) / 2;

    // Dp - 2D array
    // memset(array, 0, sizeof(array[0][0]) * m * n);
    // int Dp[len + 1][subset1Sum + 1];
    // memset(Dp, 0, len * subset1Sum * sizeof(Dp[0][0]));
    vector<vector<int>> Dp(len + 1, vector<int>(subset1Sum + 1, 0));

    //  Count the num of subset having totalSum === SUM.
    cout << "\nNumbers of subset  =>  " << SubsetCounter(Dp, vec, subset1Sum, len) << " ,\t Having Sum  =>  " << subset1Sum << endl;

    //  Dp table display
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < subset1Sum; j++)
            cout << Dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
    Divide the array into 2 parts subset1 & subset2 such that their diff is DIFFERENCE(given).

             EXPLAINATION
 1)    SubsetA + SubsetB  =  TotalSum
       SubsetA - SubsetB  =  Difference

      Equate these 2 eq linearly

 2) Resultant ::   SubsetA = ( TotalSum + Difference ) / 2;
 */
// Passing by reference saves a lot of time and makes the implementation of the code faster.
