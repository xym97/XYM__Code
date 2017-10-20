//#include<stdio.h>
//#pragma warning <diasble:4996>
//int main()
//{
//	 int arr[] = {0,5,4,8,9,1,6,4,9,5,0,3,8};
//
//     return 0;
//}
#include <stdio.h>
#include<stdlib.h>
int find_one_bit(int num)
{
    int bit = 0;
    while (num)
    {
        if (num & 1 == 1)
            return bit;
        bit++;
        num = num >> 1;
    }
    return -1;
}

void find_num(int arr[], int size, int *p1, int *p2)
{
    int tmp = 0;
    int i = 0;
    int pos = 0;
    for (i = 0; i < size; i++)
    {
        tmp ^= arr[i];
    }
    pos = find_one_bit(tmp);
    for (i = 0; i < size; i++)
    {
        if (1 & (arr[i] >> pos))
            *p1 ^= arr[i];
        else
            *p2 ^= arr[i];
    }
}
int main()
{
    int arr[] = {0,5,3,4,8,9,1,6,4,9,5,0,1,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num1 = 0;
    int num2 = 0;
    find_num(arr, size, &num1, &num2);
    printf("%d %d\n", num1, num2);
    system("pause");
    return 0;
}