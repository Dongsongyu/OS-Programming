/*************************************************************************
	> File Name: ep06.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Aug 2024 08:27:25 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 100

int main()
{
    int sum1 = 0, sum2 = 0;
    for(int i = 1;i <= MAX_N; i++){
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}
