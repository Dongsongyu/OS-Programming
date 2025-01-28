/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Jan 2025 09:37:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void output(int *arr, int n, int ind = -1) {
	int len = 0;
	for (int i = 0; i < n; i++) {
		len += printf("%4d", i);
	}
	printf("\n");
	for (int i = 0; i < len; i++) printf("-");
	printf("\n");
	for (int i = 0; i < n; i++) {
		if (i == ind) printf("\033[1;32m");
		printf("%4d", arr[i]);
		if (i == ind) printf("\033[0m");
	}
	printf("\n");
	return ;
}

int binary_search(int *arr, int n, int x) {
	int head = 0, tail = n - 1, mid;
	while (head <= tail) {
		mid = (head + tail) / 2;
		printf("[%d, %d], mid = %d, arr[%d] = %d\n", 
		head, tail, mid,
		mid, arr[mid]);
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) head = mid + 1;
		else tail = mid - 1;
	}	
	return -1;
}

void test_binary_search(int n) {
	int *arr = (int *)malloc(sizeof(int) * n);
	arr[0] = rand() % 10;
	for (int i = 1; i < n; i++) arr[i] = arr[i - 1] + rand() % 10;
	output(arr, n);
	int x;
	while (~scanf("%d", &x)) {
		if (x == -1) break;
		int ind = binary_search(arr, n, x);
		output(arr, n, ind);
	}
	free(arr);
	return ;
}

int main()
{
	#define MAX_N 10
	test_binary_search(MAX_N);

	return 0;
}