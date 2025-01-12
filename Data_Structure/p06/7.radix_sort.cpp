/*************************************************************************
	> File Name: 7.radix_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Jan 2025 10:48:35 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

void radix_sort(int *arr, int l, int r) {
	#define K 65536
	int *cnt = (int *)malloc(sizeof(int) * K);
	int *temp = (int *)malloc(sizeof(int) * (r - l));
	//round 1 个位
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
	for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i];
	memcpy(arr + l, temp, sizeof(int) * (r - l));
	//rount 2 十位
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++) cnt[arr[i] / K] += 1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
	for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] / K]] = arr[i];
	memcpy(arr + l, temp, sizeof(int) * (r - l));

	return ;
}

int main()
{
	int *arr_s = getRandData(SMALL_DATA_N);
	int *arr_b = getRandData(BIG_DATA_N);
	TEST(radix_sort, arr_s , SMALL_DATA_N);
	TEST(radix_sort, arr_b, BIG_DATA_N);
	free(arr_b);
	free(arr_s);

	return 0;
}