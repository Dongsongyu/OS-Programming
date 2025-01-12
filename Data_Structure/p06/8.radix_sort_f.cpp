/*************************************************************************
	> File Name: 8.radix_sort_f.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Jan 2025 11:29:19 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 65536  // 基数范围

// 基数排序函数
void radix_sort(int *arr, int l, int r) {
    int *cnt = (int *)malloc(sizeof(int) * K);   // 计数器数组
    int *temp = (int *)malloc(sizeof(int) * (r - l)); // 临时数组

    // 分离负数和正数
    int neg_count = 0;  // 负数的个数
    for (int i = l; i < r; i++) {
        if (arr[i] < 0) neg_count++;
    }

    int pos_count = r - l - neg_count; // 正数的个数

    // 将负数和正数分开存放
    int *neg = (int *)malloc(sizeof(int) * neg_count);
    int *pos = (int *)malloc(sizeof(int) * pos_count);

    int neg_idx = 0, pos_idx = 0;
    for (int i = l; i < r; i++) {
        if (arr[i] < 0) {
            neg[neg_idx++] = -arr[i];  // 转为正数存储负数绝对值
        } else {
            pos[pos_idx++] = arr[i];
        }
    }

    // 对正数部分进行基数排序
    memset(cnt, 0, sizeof(int) * K);
    for (int i = 0; i < pos_count; i++) cnt[pos[i] % K]++;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = pos_count - 1; i >= 0; i--) temp[--cnt[pos[i] % K]] = pos[i];
    memcpy(pos, temp, sizeof(int) * pos_count);

    // 对负数部分进行基数排序（按绝对值排序）
    memset(cnt, 0, sizeof(int) * K);
    for (int i = 0; i < neg_count; i++) cnt[neg[i] % K]++;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = neg_count - 1; i >= 0; i--) temp[--cnt[neg[i] % K]] = neg[i];
    memcpy(neg, temp, sizeof(int) * neg_count);

    // 将负数部分翻转并转换回负数，再与正数部分合并
    for (int i = 0; i < neg_count; i++) {
        arr[i] = -neg[neg_count - 1 - i];
    }
    for (int i = 0; i < pos_count; i++) {
        arr[neg_count + i] = pos[i];
    }

    // 释放内存
    free(cnt);
    free(temp);
    free(neg);
    free(pos);
}

int main() {
    int arr[] = {-10, -200, 3, 45, -8, 0, 19, -15, 32, -50};
    int size = sizeof(arr) / sizeof(arr[0]);

    radix_sort(arr, 0, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


