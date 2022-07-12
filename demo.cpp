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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // printf("\n ab");
    // printf("\b si");
    // printf("\r ha");

    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    int *q = (arr + 1);

    //  *(arr + 1)  -->  a[1] ele
    //  (arr + 1)  -->  address of a[1]
    // p = arr;  // points to the 0th index.
    // int *z =  (&arr + 2)  --> address of the a[0] + 1,
    /*
       means address of a[0] = 1000 , a[1] = 1004 ...
        z =  points to the next location after all the addressess of values in an array arr[] means 5 elements having size 4 each (5 * 4 = 20)
               (1000 + 20) + 8 = 1028.
     */
    // p = (&arr + 1);

    cout << "p  = " << p << " *p  = " << *p << endl;
    cout << "sizeof(p) = " << sizeof(p) << " sizeof(*p) = " << sizeof(*p) << endl;
    cout << (&arr + 2) << endl;

    int temp;
    int arr1[10] = {1, 2, 3, 4, 5, 6, 9, 8};
    temp = (arr1 + 1)[3]; //  address of a[1]  =  1004[3]  = means index val of from address 1004
    cout << temp << endl; //  5

       return 0;
}