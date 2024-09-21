//3或5的倍数,求1000以内的和
#include<stdio.h>
#define MAX_N 1000

int is_val(int n)
{
    return (n%3 == 0|| n%5 == 0);
}

int main()
{
    int sum = 0;
    for(int i = 1;i < MAX_N;i++){
        if(is_val(i)) sum +=i;
    }
    printf("%d\n",sum);

    return 0;
}
