/*************************************************************************
	> File Name: ep18-1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 10:05:37 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 15

int dp[MAX_N + 5][MAX_N + 5];

int main()
{
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j <= i; j++){
            cin >> dp[i][j];
        }
    }
    for(int i = MAX_N - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
