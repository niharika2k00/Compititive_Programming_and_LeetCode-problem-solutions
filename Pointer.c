
#include <stdio.h>

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
    //   *************    TYPE - 1    *************
    // char *ptr = "GeeksQuiz";
    // printf("%c\n", *&*&*ptr); //  & * cancel out
    // printf("Next character element : %c , \nNext alphabet : %c\n", *(ptr + 1), *ptr + 1);

    // *************  TYPE - 2   *************
    // char x = 'A';
    // printf("ASCII value  :  %d\n", x);
    // char *xx = "ab";

    // int *y;
    // float *z;

    // printf("%d\n", *xx);                                                                           //  ASCII  value
    // printf("Integer Pointer Size => %ld\t , Integer Pointer Size => %ld\n", sizeof(y), sizeof(z)); //  Size of a Pointer

    // *************  TYPE - 3   *************
    // char a[] = "Hello world";
    // char *b = "Hello world"; // string in C
    // printf("Size of the Character Array ==> %d\t , Size of the Character String ==> %d\n ", sizeof(a), sizeof(b));
    // printf("Character  :  %c\n ", *b);

    // char c[] = "";
    // char *d = "";

    // printf("Size of the Pointer  :  %d\n", sizeof(d));

    // *************  TYPE - 4   *************
    // float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    // float *ptr1 = &arr[0];
    // float *ptr2 = ptr1 + 3; // ptr2 points to the  [3 * sizeof(int)] = 3 * 4 = 12 means points 90.5

    // printf("%f ", *ptr2);      // Value :  90.500000
    // printf("%d", ptr2 - ptr1); //  [12 - 0] / 4 (size of int)  =  12 / 4 = 3

    // *************  TYPE - 5   *************
    // int arr[] = {1, 9, 3, 4, 5};
    // int *p = arr;

    // ++*p;   //  ++(*p)  increment value of arr[0].
    // p += 2; //  shift +2  cell points to the 3rd element.
    // printf("%d", *p);

    // *************  TYPE - 6  [all pointing the Base Address]  *************
    int arr[4][4];
    printf("%d\n", arr);
    printf("%d\n", *arr);
    printf("%d\n", arr[0]);

    char g[] = "geeksforgeeks";
    printf("%d\n", g[6]); // 111
    printf("%c\n", g[6]); // o
    printf("%s\n", g[6]); // no output

    printf("%s", g + g[6] - g[8]);

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
