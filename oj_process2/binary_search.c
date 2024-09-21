/*************************************************************************
	> File Name: binary_search.c
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Sep 2024 03:58:53 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 500

//待查找的区间是满足单调递增的
int binary_search(int *arr,int n,int val){
    int head = 0, tail = n - 1, mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(arr[mid] == val) return mid;
        if(arr[mid] < val)  head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    int arr[MAX_N + 5] = {0};    
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    while(scanf("%d", &k) != EOF){
        int index = binary_search(arr, n, k);
        printf("search %d from array: %d\n", k, index);
    }

    return 0;
}
