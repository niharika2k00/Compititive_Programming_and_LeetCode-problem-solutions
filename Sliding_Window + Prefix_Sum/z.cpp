#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long evaluatePrefixSum(vector<long long> &v, int x, int y)
{
    if (x == -1)
        return v[y];
    else
        return v[y] - v[x];
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    {
        int n, b, a;
        cin >> n >> b >> a;
        vector<long long> vect;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            vect.push_back(x);
        }
        int size = b;
        vector<long long> sumVect;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + vect[i];
            sumVect.push_back(sum);
        }
        double maxValue = 0.0;
        while (size >= a)
        {
            for (int i = size - 1; i < n; i = i + size - 1)
            {
                double value = evaluatePrefixSum(sumVect, i - size, i);
                //cout<<value<<endl;
                maxValue = max(maxValue, value * 1.0 / size);
            }
            size--;
        }
        printf("%.7f", maxValue);
        cout << endl;
    }
    return 0;
}