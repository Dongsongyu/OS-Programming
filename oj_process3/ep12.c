/*************************************************************************
	> File Name: ep12.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Sep 2024 09:20:33 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

long long triangle(int n)
{
    return (1 + n) * n >> 1;
}

int get_factor(long long val){
    int cnt = 0, I = sqrt(val);
    for(int i = 1; i <= I; i++){
        if(val % i == 0) cnt += 2;
    }
    return cnt;
}

int main()
{
    int n = 7;
    while(1){
        n++;
        long long val = triangle(n);
        if(get_factor(val) <= 500) continue;
        printf("%lld\n", val);
        break;
    }

    return 0;
}
