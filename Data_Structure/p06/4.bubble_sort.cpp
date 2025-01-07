/*************************************************************************
	> File Name: 4.bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Jan 2025 09:55:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "0.sort_test.h"

void bubble_sort(int *arr, int l, int r) {
    for (int i = r - 1, I = l + 1; i >= I; i--) {
        int cnt = 0;
        for (int j = l; j < i; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            cnt += 1;
        }
        if (cnt == 0) break;
    }
    return ;
}

int main()
{
    int *arr = getRandData(SMALL_DATA_N);
    TEST(bubble_sort, arr, SMALL_DATA_N);
    free(arr);

    return 0;
}
