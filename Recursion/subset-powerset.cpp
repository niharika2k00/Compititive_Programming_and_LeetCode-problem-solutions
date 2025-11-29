
// Finding the power set of the subset -----> 2^n number of elements in Power Set
#include <bits/stdc++.h>
using namespace std;

int totalSubset = 0;

void powerSet(vector<int> arr, vector<int> ans, int index)
{
    // when all the elements are already traversed End Printing loop .....
    if (index >= arr.size())
    {
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
        totalSubset++;
        return;
    }

    // NOT taking a new element  ---> moves to the next index
    powerSet(arr, ans, index + 1);

    // when taking a new element
    ans.push_back(arr[index]);
    powerSet(arr, ans, index + 1);
}

int main()
{
    int i, n;
    cout << "Enter the size of the Set : ";
    cin >> n;
    vector<int> arr(n);
    vector<int> subset;

    cout << "Elements of the Set are : ";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Power Set of the Array = \n";
    powerSet(arr, subset, 0);
}