
#include <stdio.h>

void fun(char **);

void fun(char **p)
{
    char *t;
    t = (p += sizeof(int))[-1];
    printf("%s\n", t); // hat
}

void fun1(int b[][3])
{
    ++b;
    b[1][1] = 15;
}

int main()
{
    char *arr[] = {"bat", "cat", "fat", "hat", "mat", "pat"};
    fun(arr);

    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    fun1(arr1);
    printf("%d\n", arr1[2][1]);

    int arr3[] = {1.2, 2.4, 3.6, 4.8, 5};
    int j, *ptr = arr3; // stores base address
    for (j = 0; j < 5; j++)
    {
        printf("%d ", *arr3);
        ++ptr;
    }
    
    return 0;
}
