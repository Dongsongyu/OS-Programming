/*************************************************************************
	> File Name: ep46.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Sep 2024 04:32:19 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};
void init_prime()
{
    for(int i = 2; i <= MAX_N; i++){
        if(!prime[i]) {
            prime[++prime[0]] = i;
            is_prime[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] > MAX_N) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main()
{
    init_prime();
    for(int i = 1; i <= prime[0]; i++){
        for(int n = 1; ; n++){
            if(prime[i] + 2 * n * n > MAX_N) break;
            is_prime[prime[i] + 2 * n * n] = 1;
        }
    }
    for(int i = 9; i <= MAX_N;i += 2){
        if(is_prime[i]) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
