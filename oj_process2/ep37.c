/*************************************************************************
	> File Name: ep37.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Sep 2024 04:13:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {1, 1, 0};//标记是否为素数
void init_prime()
{
    for(int i = 2; i <= MAX_N; i++){
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int n){
    //left
    int h = pow(10, floor(log10(n))), x = n;
    while(n){
        if(is_prime[n]) return 0;
        n %= h;
        h /= 10;
    }
    //right
    while(x){
        if(is_prime[x]) return 0;
        x /= 10;
    }
    return 1;
}

int main()
{
    init_prime();
    int sum = 0,flag = 11;
    //2,3,5,7不能作为可截素数
    for(int i = 5; i <= prime[0] && flag; i++){
        if(!is_val(prime[i])) continue;
        sum += prime[i];
        --flag;
    }
    printf("%d, flag = %d\n", sum, flag);
    return 0;
}
