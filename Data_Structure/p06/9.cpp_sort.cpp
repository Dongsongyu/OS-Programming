/*************************************************************************
	> File Name: 9.cpp_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Jan 2025 03:29:43 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include "0.sort_test.h"
using namespace std;

void output(int *arr, int n);
void output1(int *arr, int n, const char *s);
template<typename T>
void output(vector<T> &arr);

void test1() {
	//sort array
	printf("\ntest array: \n");
	int *arr = getRandData(10);
	output(arr, 10);
	sort(arr, arr + 10);//[)
	output(arr, 10);
	sort(arr, arr + 10, greater<int>());
	output(arr, 10);
	free(arr);
	return ;
}

void test2() {
	printf("\ntest vector: \n");
	//sort vector
	vector<int> arr;
	for (int i = 0; i < 10; i++) arr.push_back(rand() % 10000);
	output(arr);
	sort(arr.begin(), arr.end());
	output(arr);
	sort(arr.begin(), arr.end(), greater<int>());
	output(arr);

	return ;
}

struct Data {
	int x, y;
};

ostream &operator<<(ostream &out, const Data &d) {
	out << "(" << d.x << ", " << d.y << ")";
	return out;
}

bool cmp(const Data &a, const Data &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y > b.y;
}

void test3() {
	printf("test my data structure: \n");
	vector<Data> arr;
	for (int i = 0; i < 10; i++) {
		Data d;
		d.x = rand() % 10, d.y = rand() % 10;
		arr.push_back(d);
	}
	output(arr);
	sort(arr.begin(), arr.end(), cmp);
	output(arr);

	return ;
}

template<typename T>
void output(vector<T> &arr) {
	printf("arr[%lu] = ", arr.size());
	for(int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	printf("\n");
	return ;
}

void output(int *arr, int n) {
	printf("arr[%d] = ",  n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return ;
}

void output1(int *arr, int n, const char *s = "arr") {
	printf("%s[%d] = ", s, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return ;
}

void test4() {
	printf("\ntest sort ind : \n");
	int *arr = getRandData(10);
	int *ind = getRandData(10);
	for (int i = 0; i < 10; i++) ind[i] = i;
	output1(arr, 10);
	sort(ind, ind + 10, [&](int i, int j)->bool {
		return arr[i] < arr[j];
	});
	output(arr, 10);
	output1(ind, 10, "ind");
	return ;
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}