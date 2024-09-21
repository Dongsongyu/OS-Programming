/*************************************************************************
	> File Name: ep14.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Sep 2024 03:05:17 PM CST
 ************************************************************************/

//n --> n/2(n是偶数)
//n --> 3n+1(n是奇数)
#include<stdio.h>
#define MAX_N 1000000

int calc_len(long long n)
{
    if(n == 1) return 1;
    //按位与1
    if(n & 1) return calc_len(n * 3 + 1) + 1;
    return calc_len(n >> 1) + 1;
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
