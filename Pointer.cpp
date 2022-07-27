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

    printf("Hello");
    char s[4] = {'\b', '\r', '\t', '\n'};
    for (int i = 0; i < 4; i++)
        printf("%c", s[i]);

    //  *(arr + 1)  -->   ValueOf( Base address + 4 bytes for 1 index)  means  Value( address a[1] ) ele
    //  *arr + 4   -->   ValueOf(a[0])  +  4
    //  (arr + 1)  -->  address of a[1]

    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr; // points to the 0th index.
    int *q = (arr + 1);
    int *z = arr; //   --> address of the a[0] + 2,
    /*
       means address of a[0] = 1000 , a[1] = 1004 ...
        z =  points to the next location after all the addressess of values in an array arr[] means 5 elements having size 4 each (5 * 4 = 20)
               (1000 + 20) + 8 = 1028.
    */
    // p = (&arr + 1);

    cout << "\nZ ==> " << *z << "\tAfter add 3  ==> " << *z + 3 << endl;
    cout << "p  = " << p << " \t*p  = " << *p << endl;
    cout << "sizeof(p) = " << sizeof(p) << "\tsizeof(*p) = " << sizeof(*p) << endl;
    cout << (*arr + 6) << "\t" << (&arr + 2) << endl;

    cout << (arr + 1)[3] << endl; //  address of a[1]  =  1004[3]  = means index val of from address 1004

    int a, b, c;
    int ARR[5] = {1, 2, 3, 25, 7};
    a = ++ARR[1];
    b = ARR[1]++;
    c = ARR[a++];
    printf("a = %d , b = %d , c = %d\n", a, b, c);

    return 0;
}