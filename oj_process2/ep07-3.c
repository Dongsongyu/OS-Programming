/*************************************************************************
	> File Name: ep07-3.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Sep 2024 08:46:09 PM CST
 ************************************************************************/

//线性筛算法
//用整数M去标记合数N
//N中最小的素数P
//N可以表示成为P*M(除N以外最大的整数)
//P一定小于等于M中最小的素因子
//利用P'(所有不大于M中最小素数的集合)*M标记N1...
#include<stdio.h>
#define MAX_N 200000

//prime[0]表示素数的个数
int prime[MAX_N + 5] = {0};
void init_prime()
{
    for(int i = 2; i <= MAX_N; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if(i * prime[j] == 0) break;
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
