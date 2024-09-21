/*************************************************************************
	> File Name: ep05.c
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Sep 2024 07:02:45 PM CST
 ************************************************************************/

#include<stdio.h>
//欧几里德算法
//将大问题转化为小问题 -- 递归

int gcd(long long a,long long b)
{
    return (b ? gcd(b, a % b) : a);
}

int lcm(long long a,long long b)
{
    return a / gcd(a , b) * b;
}
//gcd(a, b) = r
//a = r * x, b = r * y
//lcm(a , b) = a * b/ gcd(a,b)

int main()
{
    long long ans = 1;
    for(int  i = 2; i<= 20; i++){
        ans = lcm(ans, i);
    }
    printf("%lld\n",ans);
    return 0;
}
