/*************************************************************************
	> File Name: ep04.c
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Aug 2024 08:58:24 PM CST
 ************************************************************************/

#include<stdio.h>

int is_revese(int n)
{
    int temp = 0,x = n;
    while(x){
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return temp == n;
}

int main()
{
    int ans = 1;
    for(int a = 100;a < 1000;a++){
        for(int b = 100;b < 1000;b++){
            if(is_revese(a * b) && a * b > ans){
                ans = a * b;
                printf("%d * %d = %d\n",a,b,ans);
            }
        }
    }
    printf("ans = %d\n",ans);
    return 0;
}
