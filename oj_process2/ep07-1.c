/*************************************************************************
	> File Name: ep07-1.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Sep 2024 07:45:57 PM CST
 ************************************************************************/

//素数筛算法
#include<stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = {0};
void init_prime(){
    for(int i = 2; i <= MAX_N; i++){
        if(prime[i]) continue;
        prime[++prime[0]] = i;//精髓
        for(int j = 2; j <= MAX_N/i; j++){
            prime[i * j] = 1;
        }
    }
    return ;
}

int main()
{
    init_prime();
    printf("%d\n",prime[10001]);

    return 0;
}
