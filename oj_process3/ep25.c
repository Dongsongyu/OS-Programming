/*************************************************************************
	> File Name: ep25.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Sep 2024 08:24:07 AM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000

int fib[3][MAX_N + 5] = {{0, 0},{1, 1},{1, 1}};

int main()
{
    int n = 2;
    while(fib[n % 3][0] < MAX_N){
        n += 1;
        int *a = fib[n % 3];
        int *b = fib[(n - 1) % 3];
        int *c = fib[(n - 2) % 3];
        for(int i = 1; i <= b[0]; i++){
            a[i] = b[i] + c[i];
        }
        a[0] = b[0];
        for(int i = 1; i <= a[0]; i++){
            if(a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (a[0] == i);
        }
    }
    printf("%d\n", n);
    return 0;
}
