/*************************************************************************
	> File Name: ep08.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Sep 2024 04:59:57 PM CST
 ************************************************************************/

//滑动窗口法
//逆运算 -- 减法是加法的逆运算 -- 除法是乘法的逆运算
#include <stdio.h>
#include "ep08.h"

int main()
{
    long long p = 1, zero = 0, ans = 0;
    for(int i = 0; num[i]; i++){
        if(num[i] = '0'){
            zero += 1;
        }
        else{
            p *= (num[i] - '0');
        }
        if(i < 13) continue;
        if(num[i - 13] == '0'){
            zero -= 1;
        }
        else{
            p /= (num[i - 13] - '0');
        }
        if(zero == 0 && p > ans) ans = p;
    }
    printf("%lld\n", ans);

    return 0;
}
