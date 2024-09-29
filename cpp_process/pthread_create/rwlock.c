/*************************************************************************
	> File Name: rwlock.c
	> Author: 
	> Mail: 
	> Created Time: Sun 29 Sep 2024 03:20:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>

#define MAX 100
//全局变量
int number = 0;

//定义读写锁
pthread_rwlock_t rwlock;

//读的线程处理函数
//多个线程可以如果处理动作相同，可以使用相同的处理函数
//每个线程中的栈资源是独享
void* read_num(void* arg)
{
    for(int i = 0; i < MAX; i++){
        pthread_rwlock_rdlock(&rwlock);
        printf("Thread A , id = %lu, number = %d\n", pthread_self(), number);
        pthread_rwlock_unlock(&rwlock);
        usleep(rand() % 100);
    }

    return NULL;
}

//写的线程的处理函数
void* write_num(void* arg)
{
    for(int i = 0; i < MAX; i++){
        pthread_rwlock_wrlock(&rwlock);
        int cur = number;
        cur++;
        number = cur;
        printf("Thread B, id = %lu, number = %d\n", pthread_self(), number);
        pthread_rwlock_unlock(&rwlock);
        //添加sleep目的是要看到多个线程交替工作
        usleep(rand() % 100);
    }

    return NULL;
}

int main(int argc, const char* argv[])
{
    pthread_t r1[5],w2[3];

    //初始化读写锁
    pthread_rwlock_init(&rwlock, NULL);

    //创建两个子线程
    for(int i = 0; i < 5; ++i){
        pthread_create(&r1[i], NULL, read_num, NULL);
    }

    for(int i = 0; i < 3; ++i){
        pthread_create(&w2[i], NULL, write_num, NULL);

    }
    //阻塞，资源回收
    for(int i = 0; i < 5; ++i){
        pthread_join(r1[i], NULL);
    }

    for(int i = 0; i < 3; ++i){
        pthread_join(w2[i], NULL);
    }
    //销毁读写锁
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
