/*************************************************************************
	> File Name: ep15.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Sep 2024 03:47:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
    long long n = 40, m = 20, ans = 1;
    while(m > 1){
        if(n > 20) ans *= (n--);
        if(m && ans % m == 0) ans /= (m--);
    }
    printf("%lld\n", ans);
    return 0;
}
