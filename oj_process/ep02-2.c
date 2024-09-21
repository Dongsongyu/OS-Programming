/*************************************************************************
	> File Name: ep02-2.c
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Aug 2024 07:16:57 PM CST
 ************************************************************************/

//滚动变量-斐波那契数列
#include<stdio.h>
#define MAX_N 4000000

int main()
{
    int a = 1,b = 2,sum = 2;    
    while(a + b < MAX_N){
        a = a + b;
        //保证b一定是大的那个值
        a ^= b;
        b ^= a;
        a ^= b;
        if(!(b & 1)) sum += b;
    }
    printf("%d\n",sum);

    return 0;
}
