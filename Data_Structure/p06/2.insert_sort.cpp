/*************************************************************************
	> File Name: 2.insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jan 2025 08:25:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "0.sort_test.h"

void insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (j > l && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    //不破坏插入排序的稳定性
    //swap(arr[l],arr[ind]);
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}

int main()
{
    int *arr = getRandData(BIG_DATA_N);
    TEST(insert_sort, arr, BIG_DATA_N);
    TEST(unguarded_insert_sort, arr, BIG_DATA_N);
    free(arr);
    return 0;
}
