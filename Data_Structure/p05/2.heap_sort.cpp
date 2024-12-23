/*************************************************************************
	> File Name: 2.heap_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Dec 2024 09:40:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define cmp >
#define ROOT 1
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)
#define swap(a, b) { \
	__typeof(a) __c = (a); \
	(a) = (b), (b) = __c; \
}
#define TEST(func, arr, n) { \
	printf("Test : %s ", #func); \
	int *temp = (int *)malloc(sizeof(int) * n); \
	memcpy(temp, arr, sizeof(int) * n); \
	long long b = clock(); \
	func(temp, n); \
	long long e = clock(); \
	if(check(temp, n)) { \
		printf("OK\t"); \
	} else { \
		printf("FAIL\t"); \
	} \
	printf("%lld ms\n", 1000 * (e - b) / CLOCKS_PER_SEC); \
	free(temp); \
}

void up_update(int *data, int i) {
	while(i > 1 && data[i] cmp data[FATHER(i)]) {
		swap(data[i], data[FATHER(i)]);
		i = FATHER(i);
	}
	return ;
}

inline void down_update(int *data, int i, int n) {
	while (LEFT(i) <= n) {
		int ind = i, l = LEFT(i), r = RIGHT(i);
		if (data[l] cmp data[ind]) ind = l;
		if (r <= n && data[r] cmp data[ind]) ind = r;
		if(ind == i) break;
		swap(data[ind], data[i]);
		i = ind;
	}

	return ;
}

int *getRandData(int n) {
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
	return arr;
}

bool check(int *arr, int n) {
	for(int i = 1; i < n; i++) {
		if(arr[i] < arr[i - 1]) return false;
	}
	return true;
}

inline void normal_heap_build(int *data, int n) {
	for (int i = 2; i < n; i++) {
		up_update(data, i);
	}
	return ;
}

inline void linear_heap_build(int *data, int n) {
	for(int i = n / 2; i >= 1; i--) {
		down_update(data, i, n);
	}
	return ;
}

void heap_sort_final(int *data, int n) {
	for(int i = n; i >= 2; i--) {
		swap(data[1], data[i]);
		down_update(data, 1, i - 1);
	}
	return ;
}

void normal_heap(int *arr, int n) {
	int *data = arr - 1;
	normal_heap_build(data, n);
	heap_sort_final(arr, n);
	return ;
}

void linear_heap(int *arr, int n) {
	int *data = arr - 1;
	linear_heap_build(data, n);
	heap_sort_final(arr, n);
	return ;
}

int main()
{
	srand(time(0));
	#define MAX_N 1000000
	int *arr = getRandData(MAX_N);
	TEST(normal_heap, arr, MAX_N);
	TEST(linear_heap, arr, MAX_N);

	return 0;
}