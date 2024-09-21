/*************************************************************************
	> File Name: ep14.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Sep 2024 03:05:17 PM CST
 ************************************************************************/

//n --> n/2(n是偶数)
//n --> 3n+1(n是奇数)
//记忆化: 将中间的计算结果保存起来，减少重复计算
//常用在搜索算法中，被称为记忆化搜索
//例: 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1
//13 --> 40 --> 20 --> 10 之前已经存在10,已知10
#include<stdio.h>
#define MAX_N 1000000

int keep[MAX_N + 5] = {0};
int calc_len(long long n)
{
    if(n == 1) return 1;
    if(n <= MAX_N && keep[n]) return keep[n];
    int ret = 0;
    //按位与1
    ret = ((n & 1) ? calc_len(n * 3 + 1) + 1 : calc_len(n >> 1)) + 1;
    if(n <= MAX_N) keep[n] = ret;
    return ret;
}

int main()
{
    int ans = 0, len = 0;
    for(long long i = 1; i < MAX_N; i++){
        int temp_len = calc_len(i);
        if(temp_len <= len) continue;
        ans = i;
        len = temp_len;
    }
    printf("ans = %d, len = %d\n", ans, len);

    return 0;
}
