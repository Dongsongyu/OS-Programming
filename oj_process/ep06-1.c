/*************************************************************************
	> File Name: ep06-1.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Aug 2024 08:35:00 PM CST
 ************************************************************************/

#include<stdio.h>
#define n 100

int main()
{
    int sum1 = (1 + n) * n >> 1;
    int sum2 = n * (n + 1) * (2 * n + 1)/ 6;
    printf("%d\n",sum1 * sum1 - sum2);

    return 0;
}
