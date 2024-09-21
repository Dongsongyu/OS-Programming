/*************************************************************************
	> File Name: ep18.c
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 09:17:17 AM CST
 ************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 15

int val[MAX_N + 5][MAX_N + 5];
int F[MAX_N + 5][MAX_N + 5];

int dfs(int i, int j, int n)
{
    if(i == n) return 0;
    if(F[i][j]) return F[i][j];
    int x = max(dfs(i + 1, j, n), dfs(i + 1, j + 1, n)) + val[i][j];
    F[i][j] = x;
    return x;
}

int main()
{
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j <= i; j++){
            cin>>val[i][j];
        }
    }
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ",val[i][j]);
        }
        cout << endl;
    }
    printf("------------------------\n");
    printf("%d\n", dfs(0, 0, MAX_N));

    return 0;
}
