
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
        int *z = ptr++; //  z = ptr ;  ptr = ptr + 1
        // printf("%d ", *z);  // 1 2 3 4 5
        printf("%d ", *(arr3 + 2)); //  Val(addressOf a[0] + [2*4] for 2 idx)  => Val(1000 + 8)  => Val(1008)  =>  3
    }

    printf("\n");

    // ---------------------------------------------------
    static int a[] = {0, 1, 2, 3, 4};
    int *p[] = {a, a + 1, a + 2, a + 3, a + 4}; // stores address

    //  *(a + 1)  ===  *p[1]
    printf("%d  %d  %d \n", *(a + 1), *p[0], *p[1]);

    int **ptr1 = p; //  Double Pointer ->  points to the addressOf the 1st ele in p[]
    printf("%d  %d\n", **ptr1, ++*ptr1);

    ++*ptr1;
    printf("%d %d %d", ptr1 - p, *ptr1 - a, **ptr1); //  *ptr1 - a  => addressOf(a[1]) - addressOf(s[0])
    // ---------------------------------------------------

    char s[4] = {'\0', '\0', '\0', '\0'};
    for (int i = 0; i < 4; i++)
        printf("%c \n", s[i]); // No Output.  \0 = NULL. Thus compiler prints nothing.

    int ARR[3], i = 0;
    while (i < 3)
        ARR[i] = ++i;

    for (i = 0; i < 3; i++)
        printf("%d\t", ARR[i]);

    return 0;
}
