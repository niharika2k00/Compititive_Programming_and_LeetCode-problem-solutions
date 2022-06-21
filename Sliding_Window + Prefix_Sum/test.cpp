
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printarray(int **array, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            printf("%d ", array[i][j]);
    printf("\n");
}

void print1(int (*arr)[3], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cout << arr[i][j] << "\t";
}

int main()
{
    int n = 3;
    int i, j;

    int *arr = new int[m * n];

    // int **array = (int **)malloc(n * sizeof(int *));

    // for (i = 0; i < n; i++)
    // array[i] = (int *)malloc(n * sizeof(int));

    // array = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // for (i = 0; i < n; i++)
    //     for (j = 0; j < n; j++)
    //         scanf("%c ", &array[i][j]);

    // printarray(array, n);

    int a[2][3] = {{10, 20, 30}, {40, 50, 60}};

    int r = 2;
    int c = 3;
    print1(a, r, c);
}