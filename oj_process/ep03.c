/*************************************************************************
	> File Name: ep03.c
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Aug 2024 08:08:36 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 600851475143LL

int main()
{
    long long ans = 0, i = 2, N = MAX_N;
    while(i * i <= N){
        if(N % i == 0) ans = i;
        while(N % i == 0) N /= i;
        i++;
    }
    if(N != 1) ans = N;
    printf("%lld\n",ans);

    return 0;
}
