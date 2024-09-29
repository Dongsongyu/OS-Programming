/*************************************************************************
	> File Name: pthread_create.c
	> Author: 
	> Mail: 
	> Created Time: Sun 29 Sep 2024 10:29:06 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

struct Test
{
    int num;
    int age;
};

void* callback(void* arg)
{
    for(int i = 0; i < 5; ++i){
        printf("子线程: i = %d\n", i);
    }
    printf("子线程: %ld\n", pthread_self());
    
    struct Test* t = (struct Test*)arg;
    t->num = 100;
    t->age = 6;

    pthread_exit(&t);

    return NULL;
}

int main()
{
    struct Test t;
    pthread_t tid;
    pthread_create(&tid, NULL, callback, &t);
    printf("主线程: %ld\n", pthread_self());
    
    /*void* ptr;//指向的是&t
    pthread_join(tid,&ptr);//ptr是为了给一级指针做初始化
    //pthread_join(tid, NULL);//不接收子线程数据
    printf("num: %d, age = %d\n", t.num, t.age);
    */

    pthread_detach(tid);

    pthread_exit(NULL);

    return 0;
}
